# Stack
### To build Stack the following is needed to be done:

```
mkdir build && cd build/

cmake ..
\\or with sanitizers:\\
cmake -DADD-SANITIZERS=1 ..

make

\\to run GoogleTests:\\
make run_stack_tests

\\to run GoogleBenchmark:
make run_stack_grow_factor_benchmark
```