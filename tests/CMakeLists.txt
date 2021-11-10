cmake_minimum_required(VERSION 3.16.3)
project(Stack_test VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

set(EXEC_FILE stack_tests)
set(TEST_FILE run_${EXEC_FILE})
set(INCL_PATH ../Stack/includes/)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${EXEC_FILE} stack_tests.cpp)
target_link_libraries(${EXEC_FILE} gtest_main)
target_include_directories(${EXEC_FILE} PUBLIC ${INCL_PATH}) #to be able to write include "stack_impl.hpp" instead of the whole path

include(GoogleTest)
gtest_discover_tests(${EXEC_FILE})

add_custom_target(
    ${TEST_FILE}
    COMMENT Running tests for Stack
    COMMAND ./${EXEC_FILE}
)

add_dependencies(${TEST_FILE} ${EXEC_FILE})

if (ADD_SANITIZERS)
    target_compile_options(${EXEC_FILE} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC_FILE}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

set_target_properties(
    ${EXEC_FILE} PROPERTIES
    CXX_STANDART 20
    CXX_STANDART_REQUIRED ON
)