#include <experimental/coroutine>
#include <optional>

template<typename T>
struct OptionalPromise {
    auto initial_suspend() {
        return std::experimental::suspend_never();
    }
    auto final_suspend() {
        return std::experimental::suspend_never();
    }
    void unhandled_exception() {}

    struct ReturnObject {
        ReturnObject(OptionalPromise& promise) : promise_(promise) {}
        operator std::optional<T>() {
            return promise_.optional_;
        }
        OptionalPromise& promise_;
    };
    auto get_return_object() {
        return ReturnObject(*this);
    }

    template<typename U>
    void return_value(U value) {
        optional_ = value;
    }

    std::optional<T> optional_;
};

template<typename T, typename... Args>
struct std::experimental::coroutine_traits<std::optional<T>, Args...> {
    using promise_type = OptionalPromise<T>;
};
