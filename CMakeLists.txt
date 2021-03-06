cmake_minimum_required(VERSION 3.16.3)
project(Stack VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

add_compile_options (
    -Wall -Werror -Wextra -Wpedantic -Wcast-qual -Wcast-align -Wconversion
    -Wsign-promo -Wfloat-equal -Wenum-compare -Wold-style-cast -Wredundant-decls
    -Wnon-virtual-dtor -Woverloaded-virtual 
)

include(cmake/ClangFormat.cmake)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    --format-style=file;
    --header-filter=*.hpp;
)

add_subdirectory(tests)
add_subdirectory(stack/benchmark)