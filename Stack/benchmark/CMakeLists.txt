cmake_minimum_required(VERSION 3.16.3)
project(Stack_benchmark VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

find_package(benchmark REQUIRED)

set(EXEC stack_grow_factor_benchmark)
set(RUN_EXEC run_${EXEC})

add_executable(${EXEC} stack_grow_factor_benchmark.cpp)

target_link_libraries(${EXEC} benchmark::benchmark)

add_custom_target(
    ${RUN_EXEC}
    COMMENT Running GoogleBenchmark
    COMMAND ./${EXEC}
)