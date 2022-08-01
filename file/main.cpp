//
// Created by yacopsae on 10/03/22.
//

#include "utils.hpp"
#include "file_path_config.hpp"
#include "file_sort.hpp"
#include "file_sort_v2.hpp"
#include "shell_sort.hpp"
#include "quick_sort_optimized.hpp"
#include "heap_sort.hpp"
#include "bucket_sort.hpp"
#include "radix_sort.hpp"
#include "counting_sort.hpp"
#include <map>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>

template<typename T>
tabulate::Table generate_table(
	const std::string &input_file,
	const std::map<std::string, FileSort<T> *> &sort_list_with_clause,
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

  std::ifstream ofstream;
  ofstream.open(SOURCE_FILE);
  //2s 158.9ms
  if (!ofstream.is_open())
	Utils::generate_file("/home/yacopsae/CLionProjects/algo-homework/file/generated_numbers.txt", '\n', 100000);
  ofstream.close();

  //std::map<std::string, size_t> tests;
  //tests["32"] = 32;
  //tests["64"] = 64;
  //tests["128"] = 128;
  //tests["256"] = 256;
  //tests["512"] = 512;
  //tests["1024"] = 1024;
  //tests["16384"] = 16384;
  //tests["32768"] = 32768;
  //tests["65536"] = 65536;
  //tests["131072"] = 131072;
  //tests["262144"] = 262144;

  //std::string sort_result(SORT_RESULT);
  //std::map<std::string, FileSort<long> *> exponent;
  //exponent["ShellSort"] = new FileSort<long>{new ShellSort<long>(), sort_result};
  //exponent["OptimizedQuickSort"] = new FileSort<long>{new OptimizedQuickSort<long>(), sort_result};
  //exponent["HeapSort"] = new FileSort<long>{new HeapSort<long>(), sort_result};
  //exponent["BucketSort"] = new FileSort<long>{new BucketSort<long>(), sort_result};
  //exponent["CountingSort"] = new FileSort<long>{new CountingSort<long>(), sort_result};
  //exponent["RadixSort"] = new FileSort<long>{new RadixSort<long>(), sort_result};

  auto * merge_file_sort = new MergeFileSort(SORT_RESULT);
  std::cout << Utils::test_file_sorting_for_table(SOURCE_FILE, merge_file_sort);


  //tabulate::MarkdownExporter exporter;
  //std::cout << "Sorting 10000 numbers file" << std::endl;
  //auto exponent_table = generate_table(FILE_INPUT, exponent, tests);
  //std::cout << std::endl << std::endl << std::endl << exporter.dump(exponent_table) << std::endl;

}
