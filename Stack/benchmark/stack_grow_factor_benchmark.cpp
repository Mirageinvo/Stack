#include <benchmark/benchmark.h>

#include "../includes/Stack.hpp"
#include "../includes/Stack_impl.hpp"

const int kStartGrowFactor = 12;
const int kFinalGrowFactor = 25;
const int kGrowFactorStep = 1;
const int kNumOfPushes = 1e6;

static void BM_Stack_Grow_Factor(benchmark::State& state) {
  for (auto _ : state) {
    Stack<int> st = Stack<int>(static_cast<double>(state.range()) / 10.0);
    for (int i = 0; i < kNumOfPushes; ++i) {
      st.push(1);
    }
  }
}

BENCHMARK(BM_Stack_Grow_Factor)
    ->DenseRange(kStartGrowFactor, kFinalGrowFactor, kGrowFactorStep)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();