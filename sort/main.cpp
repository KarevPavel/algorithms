//
// Created by yacopsae on 11/02/22.
//

#include <shell_sort.hpp>
#include "utils.hpp"
#include <algorithm>
#include <selection_sort.hpp>
#include <heap_sort.hpp>
#include <quick_sort_original.hpp>
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "optimized_bubble_sort.hpp"

int main() {
  Utils::test_sorting("BubbleSort", 100, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 100, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 100, new InsertionSort());
  Utils::test_sorting("Original - ShellSort", 100, new ShellSort());
  Utils::test_sorting("SelectionSort", 100, new SelectionSort());
  Utils::test_sorting("HeapSort", 100, new HeapSort());
  Utils::test_sorting("Original - QuickSort", 100, new OriginalQuickSort());

  Utils::test_sorting("BubbleSort", 1000, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 1000, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 1000, new InsertionSort());
  Utils::test_sorting("Original - ShellSort", 1000, new ShellSort());
  Utils::test_sorting("SelectionSort", 1000, new SelectionSort());
  Utils::test_sorting("HeapSort", 1000, new HeapSort());
  Utils::test_sorting("Original - QuickSort", 1000, new OriginalQuickSort());

  Utils::test_sorting("BubbleSort", 10000, new BubbleSort());
  Utils::test_sorting("Optimized - BubbleSort", 10000, new OptimizedBubbleSort());
  Utils::test_sorting("InsertionSort", 10000, new InsertionSort());
  Utils::test_sorting("Original - ShellSort", 10000, new ShellSort());
  Utils::test_sorting("SelectionSort", 10000, new SelectionSort());
  Utils::test_sorting("HeapSort", 10000, new HeapSort());
  Utils::test_sorting("Original - QuickSort", 10000, new OriginalQuickSort());

  Utils::test_sorting("Original - QuickSort", 100000, new OriginalQuickSort());
  Utils::test_sorting("Original - QuickSort", 1000000, new OriginalQuickSort());
}