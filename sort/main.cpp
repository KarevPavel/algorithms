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

bool le_10000(size_t arg) {
  return arg <= 10000;
}

template <size_t max>
bool le(size_t arg) {
  return arg <= max;
}

bool no_check(size_t arg) {
  return true;
}

int main() {
  tabulate::Table sort_results;

  std::map<std::string, size_t> tests;
  tests["100"] = 100;
  tests["1000"] = 1000;
  tests["10000"] = 10000;
  tests["100000"] = 100000;
  tests["1000000"] = 1000000;
  tests["10000000"] = 10000000;

  std::map<std::string, std::pair<std::function<bool(size_t)>, ArraySort *>> sort_list_with_clause;
  sort_list_with_clause["BubbleSort"] = {&le<10000>, new BubbleSort()};
  sort_list_with_clause["Optimized - BubbleSort"] = {&le_10000, new OptimizedBubbleSort()};
  sort_list_with_clause["InsertionSort"] = {&le_10000, new InsertionSort()};
  sort_list_with_clause["Original - ShellSort"] = {&le_10000, new ShellSort()};
  sort_list_with_clause["SelectionSort"] = {&le_10000, new SelectionSort()};
  sort_list_with_clause["HeapSort"] = {&no_check, new HeapSort()};
  sort_list_with_clause["Original - QuickSort"] = {&no_check, new OriginalQuickSort()};
  sort_list_with_clause["Optimized - QuickSort"] = {&no_check, new OptimizedQuickSort()};
  sort_list_with_clause["MergeSort"] = {&no_check, new MergeSort()};

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
		result_rows.push_back(Utils::table_sorting(test_entry.second, sorting_map_entry.second.second));
	  else
		result_rows.push_back(" - ");
	sort_results.add_row(result_rows);
  }
  tabulate::MarkdownExporter exporter;
  auto markdown = exporter.dump(sort_results);
  std::cout << markdown << std::endl;
}