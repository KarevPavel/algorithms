//
// Created by yacopsae on 23/03/22.
//

#include <string>
#include <map>
#include <utils.hpp>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>
#include "hash_table.hpp"
#include "hash_table_woa.hpp"
#include "hash.hpp"
#include "map.hpp"

tabulate::Table generate_table(Map<std::string, int> *map,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)> &array_generator);

int main() {
  std::map<std::string, size_t> tests;




  //tests["10"] = 10;
  tests["20"] = 20;

  std::map<std::string, Map<std::string, int> *> random_array_tree_map;

  auto *hash_table = new HashTable<std::string, int>(Hash::simple_hash);
  random_array_tree_map["HashTable"] = hash_table;

  auto *hash_table_with_open_addressing = new HashTableWOA<std::string, int>(Hash::simple_hash);
  random_array_tree_map["HashTableWOA"] = hash_table_with_open_addressing;

  auto hash_table_result_table = generate_table(hash_table,
										   tests,
										   Utils::random_array<int>);

  auto hash_table_woa_result_table = generate_table(hash_table_with_open_addressing,
										   tests,
										   Utils::random_array<int>);
  tabulate::MarkdownExporter exporter;
  std::cout << "## Hash table" << std::endl;
  std::cout << exporter.dump(hash_table_result_table) << std::endl;

  std::cout << std::endl << std::endl << "## Hash table open addressing" << std::endl;
  std::cout << exporter.dump(hash_table_woa_result_table) << std::endl;


  return 0;
}

tabulate::Table generate_table(Map<std::string, int> *map,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)> &array_generator) {
  tabulate::Table sort_results;
  tabulate::Table::Row_t header_rows;
  header_rows.push_back("elements");
  auto headers = new std::string[3]{
	  "INSERT",
	  "CONTAINS",
	  "DELETE"
  };
  for (int i = 0; i < 3; i++)
	header_rows.push_back(headers[i]);
  sort_results.add_row(header_rows);

  for (auto const &test_entry: tests) {
	tabulate::Table::Row_t result_rows;

	int element_count = test_entry.second;
	int *array = array_generator(element_count);
	test_entry.first.begin();
	result_rows.push_back(test_entry.first);
	result_rows.push_back(Utils::test_map_insert(array, element_count, map));
	result_rows.push_back(Utils::test_map_search(array, element_count, map));
	result_rows.push_back(Utils::test_map_delete(array, element_count, map));
	sort_results.add_row(result_rows);
  }
  return sort_results;
}