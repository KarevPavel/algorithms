//
// Created by yacopsae on 11/02/22.
//

#include <shell_sort.hpp>
#include "utils.hpp"
#include <algorithm>
#include <selection_sort.hpp>
#include <heap_sort.hpp>
#include <quick_sort_original.hpp>
#include <quick_sort_optimized.hpp>
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "optimized_bubble_sort.hpp"
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>
#include <merge_sort.hpp>
#include <map>
#include <list>
#include <bucket_sort.hpp>
#include <counting_sort.hpp>
#include <radix_sort.hpp>
#include <bubble_sort_v2.hpp>

template<size_t max>
bool le(size_t arg) {
  return arg <= max;
}

bool no_check(size_t arg) {
  return true;
}

tabulate::Table generate_table(const std::map<std::string, std::pair<std::function<bool(size_t)>, ArraySort<long>*>>& sort_list_with_clause,
					const std::map<std::string, size_t>& tests) {

  tabulate::Table sort_results;
  tabulate::Table::Row_t header_rows;
  header_rows.push_back("elements");
  for (auto const &imap: sort_list_with_clause)
	header_rows.push_back(imap.first);
  sort_results.add_row(header_rows);

  for (auto const &test_entry: tests) {
	tabulate::Table::Row_t result_rows;
	result_rows.push_back(test_entry.first);
	for (auto const &sorting_map_entry: sort_list_with_clause)
	  if (sorting_map_entry.second.first(test_entry.second))
		result_rows.push_back(Utils::test_sorting_for_table(test_entry.second, sorting_map_entry.second.second));
	  else
		result_rows.push_back(" - ");
	sort_results.add_row(result_rows);
  }
  return sort_results;
}

int main() {

  std::map<std::string, size_t> tests;
  tests["100"] = 100;
  tests["1000"] = 1000;
  tests["10000"] = 10000;
  tests["100000"] = 100000;
  tests["1000000"] = 1000000;
  tests["10000000"] = 10000000;

  std::map<std::string, std::pair<std::function<bool(size_t)>, ArraySort<long>*>> exponent;
  exponent["BubbleSort"] = {&le<100000>, new BubbleSort<long>()};
  exponent["Optimized - BubbleSort"] = {&le<100000>, new OptimizedBubbleSort<long>()};
  exponent["InsertionSort"] = {&le<100000>, new InsertionSort<long>()};
  exponent["Original - ShellSort"] = {&le<100000>, new ShellSort<long>()};
  exponent["SelectionSort"] = {&le<100000>, new SelectionSort<long>()};
  exponent["BubbleSortV2"] = {&le<100000>, new BubbleSortV2<long>()};

/*  std::map<std::string, std::pair<std::function<bool(size_t)>, ArraySort<long>*>> logariphm;
  logariphm["HeapSort"] = {&no_check, new HeapSort<long>()};
  logariphm["Original - QuickSort"] = {&no_check, new OriginalQuickSort<long>()};
  logariphm["Optimized - QuickSort"] = {&no_check, new OptimizedQuickSort<long>()};
  logariphm["MergeSort"] = {&no_check, new MergeSort<long>()};


  std::map<std::string, std::pair<std::function<bool(size_t)>, ArraySort<long>*>> linear;
  //linear["BucketSort"] = {&no_check, new BucketSort<long>()};
  linear["CountingSort"] = {&no_check, new CountingSort<long>()};
  linear["RadixSort"] = {&no_check, new RadixSort<long>()};*/

  tabulate::MarkdownExporter exporter;

  std::cout << "## O(n ^ 2)" << std::endl;
  auto exponent_table = generate_table(exponent, tests);
  std::cout << exporter.dump(exponent_table) << std::endl;

  /*std::cout << "## O(n * log n)" << std::endl;
  auto logariphm_table = generate_table(logariphm, tests);
  std::cout << exporter.dump(logariphm_table) << std::endl;

  std::cout << "## O(N)" << std::endl;
  auto linear_table = generate_table(linear, tests);
  std::cout << exporter.dump(linear_table) << std::endl;*/
}

