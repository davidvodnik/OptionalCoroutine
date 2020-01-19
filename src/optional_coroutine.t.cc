#include "optional_coroutine.h"

static std::optional<int> nullopt_return() {
    co_return std::nullopt;
}
static std::optional<int> value_return() {
    co_return 42;
}

int main() {
    assert(!nullopt_return());
    assert(value_return());
    assert(value_return().value() == 42);
}
