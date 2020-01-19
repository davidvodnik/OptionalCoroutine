cmake_minimum_required(VERSION 3.15)
project(OptionalCoroutine)

set(CMAKE_CXX_STANDARD 17)

add_executable(optional_coroutine
    src/optional_coroutine.h
    src/optional_coroutine.t.cc
    )
target_compile_options(optional_coroutine PUBLIC -fcoroutines-ts)
