//
// Created by yacopsae on 21/03/22.
//

#include "bs_tree.hpp"
#include "utils.hpp"
#include <map>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>

tabulate::Table generate_table(Tree<int> *tree,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)>& array_generator,
							   const std::function<std::string(int *, int, Tree<int> *)>& func);

int main() {
  std::map<std::string, size_t> tests;
  tests["100"] = 100;
  tests["1000"] = 1000;
  tests["10000"] = 10000;
  tests["100000"] = 100000;

  std::map<std::string, Tree<int> *> random_array_tree_map;
  random_array_tree_map["BSTree"] = new BSTree<int>();
  auto *bs_tree = new BSTree<int>();

  auto random_array_table = generate_table(bs_tree,
										   tests,
										   Utils::random_array<int>,
										   Utils::test_tree_insert_random_array<Tree<int>>);

  auto asc_array_table = generate_table(bs_tree,
										tests,
										Utils::asc_array<int>,
										Utils::test_tree_insert_asc_array<Tree<int>>);

  tabulate::MarkdownExporter exporter;
  std::cout << "## ASC ARRAY" << std::endl;
  std::cout << exporter.dump(asc_array_table) << std::endl;

  std::cout << std::endl << std::endl << "## RANDOM ARRAY" << std::endl;
  std::cout << exporter.dump(random_array_table) << std::endl;

}

tabulate::Table generate_table(Tree<int> *tree,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)>& array_generator,
							   const std::function<std::string(int *, int, Tree<int> *)>& func) {
  tabulate::Table sort_results;
  tabulate::Table::Row_t header_rows;
  header_rows.push_back("elements");
  auto headers = new std::string[3]{
	  "INSERT",
	  "SEARCH",
	  "DELETE"
  };
  for (int i = 0; i < 3; i++)
	header_rows.push_back(headers[i]);
  sort_results.add_row(header_rows);

  for (auto const &test_entry: tests) {
	tabulate::Table::Row_t result_rows;

	int element_count = test_entry.second;
	int *array = array_generator(element_count);
	result_rows.push_back(test_entry.first);
	result_rows.push_back(func(array, element_count, tree));
	result_rows.push_back(Utils::test_tree_search(array, element_count, tree));
	result_rows.push_back(Utils::test_tree_delete(array, element_count, tree));
	sort_results.add_row(result_rows);
  }
  return sort_results;
}