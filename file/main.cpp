//
// Created by yacopsae on 10/03/22.
//

#include "utils.hpp"
#include "file_path_config.hpp"
#include "../sort/include/file_sort.hpp"
#include "../sort/include/shell_sort.hpp"
#include "../sort/include/quick_sort_optimized.hpp"
#include "../sort/include/heap_sort.hpp"
#include "../sort/include/bucket_sort.hpp"
#include "../sort/include/radix_sort.hpp"
#include "../sort/include/counting_sort.hpp"
#include <map>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>

tabulate::Table generate_table(
	const std::string &input_file,
	const std::map<std::string, FileSort *> &sort_list_with_clause,
	const std::map<std::string, size_t> &tests) {

  tabulate::Table sort_results;
  tabulate::Table::Row_t header_rows;
  header_rows.push_back("batch_size");
  for (auto const &imap: sort_list_with_clause)
	header_rows.push_back(imap.first);
  sort_results.add_row(header_rows);

  for (auto const &test_entry: tests) {
	tabulate::Table::Row_t result_rows;
	result_rows.push_back(test_entry.first);
	for (auto const &sorting_map_entry: sort_list_with_clause) {
	  std::cout << "START TESTING " << test_entry.second << " SIZE ALGO: " << sorting_map_entry.first << std::endl;
	  auto test_result = Utils::test_file_sorting_for_table(input_file, test_entry.second, sorting_map_entry.second);
	  std::cout << "READY RESULT: " << test_result << std::endl;
	  result_rows.push_back(test_result);
	}
	sort_results.add_row(result_rows);
  }
  return sort_results;
}

int main() {

  	//Utils::generate_file(FILE_OUTPUT, '\n',10000000);
/*

  FileSort file_sort{new ShellSort(), sort_result};
  //file_sort.file_sort(FILE_OUTPUT, 100);
*/

  std::map<std::string, size_t> tests;
  tests["32"] = 32;
  tests["64"] = 64;
  tests["128"] = 128;
  tests["256"] = 256;
  tests["512"] = 512;
  tests["1024"] = 1024;

  std::string sort_result(SORT_RESULT);
  std::map<std::string, FileSort *> exponent;
  exponent["ShellSort"] = new FileSort{new ShellSort(), sort_result};
  exponent["OptimizedQuickSort"] = new FileSort{new OptimizedQuickSort(), sort_result};
  exponent["HeapSort"] = new FileSort{new HeapSort(), sort_result};
  //exponent["BucketSort"] = new FileSort{new BucketSort(), sort_result};
  //exponent["CountingSort"] = new FileSort{new CountingSort(), sort_result};
  exponent["RadixSort"] = new FileSort{new RadixSort(), sort_result};

  tabulate::MarkdownExporter exporter;
  std::cout << "Sorting 10000000 numbers file" << std::endl;
  auto exponent_table = generate_table(FILE_OUTPUT, exponent, tests);
  std::cout << exporter.dump(exponent_table) << std::endl;

}
