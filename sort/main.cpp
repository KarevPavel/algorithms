//
// Created by yacopsae on 11/02/22.
//

#include <shell_sort.hpp>
#include "utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "optimized_bubble_sort.hpp"
#include "shifted_insertion_sort.hpp"

int main() {
  Utils::test_sorting("BubbleSort", 100, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 100, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 100, new InsertionSort());
  Utils::test_sorting("Shifted Insertion", 100, new ShiftedInsertionSort());
  Utils::test_sorting("Original - ShellSort", 100, new ShellSort());

  Utils::test_sorting("BubbleSort", 1000, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 1000, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 1000, new InsertionSort());
  Utils::test_sorting("Original - ShellSort", 1000, new ShellSort());

  Utils::test_sorting("BubbleSort", 10000, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 10000, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 10000, new InsertionSort());
  Utils::test_sorting("Original - ShellSort", 10000, new ShellSort());
}

