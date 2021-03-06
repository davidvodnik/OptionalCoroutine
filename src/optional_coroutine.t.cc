#include "optional_coroutine.h"
#include <string>

static std::optional<int> nullopt_return() {
    co_return std::nullopt;
}
static std::optional<int> value_return() {
    co_return 42;
}

static std::optional<int> nullopt_await() {
    co_await std::optional<int>();
    co_return 42;
}
static std::optional<int> value_await() {
    auto value = co_await std::optional<int>(42);
    co_return value;
}

static std::optional<int> other_await() {
    auto value = co_await std::optional<std::string>("42");
    co_return std::stoi(value);
}

int main() {
    assert(!nullopt_return());
    assert(value_return());
    assert(value_return().value() == 42);

    assert(!nullopt_await());
    assert(value_await());
    assert(value_await().value() == 42);

    assert(other_await());
    assert(other_await().value() == 42);
}
