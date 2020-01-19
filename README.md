# OptionalCoroutine
A coroutine promise type for `std::optional<T>` that enables early return.

Replaces manual checking:

```cpp
std::optional<int> main() {
    std::optional<int> result = may_fail();
    if (!result.has_value())
        return {};
    int value = result.value();
    //...
}
```

With a single co_await expression:


```cpp
std::optional<int> main() {
    int value = co_await may_fail();
    //...
}
```

