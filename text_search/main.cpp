//
// Created by yacopsae on 30/04/2022.
//
#include <string>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>
#include "scan.hpp"
#include "utils.hpp"

#define TEXT_LENGTH 5000
#define PATTERN "@@@@@@"
#define POSITION POSITION::MID
#define TEST_ITERATION_COUNT 10000
int main() {

  tabulate::Table tbl;
  tbl.add_row({
				  "FULLSCAN",
				  "PREFIXSCAN",
				  "SUFFIXSCAN"
			  });

  double fullscan_result = 0;
  double prefixscan_result = 0;
  double suffixscan_result = 0;

  for (int test_n = 0; test_n < TEST_ITERATION_COUNT; test_n++) {
	auto pair = Utils::generate_text_and_pattern(TEXT_LENGTH, PATTERN, POSITION);
	auto start = std::chrono::high_resolution_clock::now();
	Fullscan::found(pair.second, pair.first);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = end - start;
	fullscan_result += fp_ms.count();

	start = std::chrono::high_resolution_clock::now();
	PrefixScan::found(pair.second, pair.first);
	end = std::chrono::high_resolution_clock::now();
	fp_ms = end - start;
	prefixscan_result += fp_ms.count();

	start = std::chrono::high_resolution_clock::now();
	SuffixScan::found(pair.second, pair.first);
	end = std::chrono::high_resolution_clock::now();
	fp_ms = end - start;
	suffixscan_result += fp_ms.count();
  }

  tbl.add_row({
				  std::to_string(fullscan_result / TEST_ITERATION_COUNT),
				  std::to_string(prefixscan_result / TEST_ITERATION_COUNT),
				  std::to_string(suffixscan_result / TEST_ITERATION_COUNT),
			  });


  tabulate::MarkdownExporter exporter;

  std::cout << "## O(n ^ 2)" << std::endl;
  std::cout << exporter.dump(tbl) << std::endl;
}
