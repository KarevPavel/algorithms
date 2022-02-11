#include <gtest/gtest.h>
#include <fstream>
#include <chrono>
#include "list"
#include "iostream"
#include "table_generator.hpp"

class TableGeneratorTest : public testing::Test {
 protected:
  void SetUp() {
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.0.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.1.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.2.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.3.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.4.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.5.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.6.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.7.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.8.in");
	test_input_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.9.in");

	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.0.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.1.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.2.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.3.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.4.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.5.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.6.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.7.out");
	test_results_files.emplace_back(
		"/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.8.out");
	test_results_files.emplace_back("/home/yacopsae/CLionProjects/algo-homework/lucky-ticket/resources/test.9.out");

  }

  void TearDown() {
  }
  std::vector<std::string> test_input_files;
  std::vector<std::string> test_results_files;

 public:
  static long long first_line_content(const std::string &file_path) {
	std::ifstream test_file(file_path);
	std::string line;
	if (test_file.is_open()) {
	  getline(test_file, line);
	  test_file.close();
	}

	std::string::size_type pos = 0; // Must initialize
	while ((pos = line.find('\r', pos)) != std::string::npos)
	  line.erase(pos, 1);

	return std::stoll(line);
  }
};

TEST_F(TableGeneratorTest, _00) {
  long long in_arg = first_line_content(test_input_files[0]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[0]));
}

TEST_F(TableGeneratorTest, _01) {
  long long in_arg = first_line_content(test_input_files[1]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[1]));
}

TEST_F(TableGeneratorTest, _02) {
  long long in_arg = first_line_content(test_input_files[2]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[2]));
}

TEST_F(TableGeneratorTest, _03) {
  long long in_arg = first_line_content(test_input_files[3]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[3]));
}

TEST_F(TableGeneratorTest, _04) {
  long long in_arg = first_line_content(test_input_files[4]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[4]));
}

TEST_F(TableGeneratorTest, _05) {
  long long in_arg = first_line_content(test_input_files[5]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[5]));
}

TEST_F(TableGeneratorTest, _06) {
  long long in_arg = first_line_content(test_input_files[6]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[6]));
}

TEST_F(TableGeneratorTest, _07) {
  long long in_arg = first_line_content(test_input_files[7]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  EXPECT_EQ(tbl.result(), first_line_content(test_results_files[7]));
}

TEST_F(TableGeneratorTest, _08) {
  long long in_arg = first_line_content(test_input_files[8]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  tbl.print_table();
  EXPECT_EQ(tbl.result() - first_line_content(test_results_files[8]), 0);
  //EXPECT_EQ(tbl.result(), first_line_content(test_results_files[8]));
}

TEST_F(TableGeneratorTest, _09) {
  long long in_arg = first_line_content(test_input_files[9]);
  auto tbl = TableGenerator{(int)in_arg};
  tbl.generate_table();
  tbl.print_table();
  EXPECT_EQ(tbl.result() - first_line_content(test_results_files[9]), 0);
  //EXPECT_EQ(tbl.result(), first_line_content(test_results_files[9]));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int Ret = RUN_ALL_TESTS();
  return Ret;
}