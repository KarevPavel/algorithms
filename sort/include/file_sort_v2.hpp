//
// Created by yacopsae on 18/03/22.
//

#pragma once

#include <string>

class MergeFileSort {
 public:
  explicit MergeFileSort(const std::string &output_dir) :
	  a_file(output_dir + "a.txt"),
	  b_file(output_dir + "b.txt") {}

  void file_sort(const std::string &in_file_path) {
	while (split_file(in_file_path)) {
	  merge_files(in_file_path);
	}
  }

  bool split_file(const std::string &in_file_path) {
	std::ofstream a_ofstream;
	a_ofstream.open(a_file);
	if (!a_ofstream)
	  throw std::runtime_error("Cannot open file!" + a_file);

	std::ofstream b_ofstream;
	b_ofstream.open(b_file);
	if (!b_ofstream)
	  throw std::runtime_error("Cannot open file! " + b_file);

	std::ifstream ifstream;
	ifstream.open(in_file_path);
	if (!ifstream)
	  throw std::runtime_error("Cannot open file! " + in_file_path);

	int number;
	int a_number = std::numeric_limits<int>::min();
	int b_number = std::numeric_limits<int>::min();
	bool write_to_a_file = true;
	bool stream_was_swapped = false;

	int a_count = 0;
	int b_count = 0;
	int total_count = 0;
	int stream_swap_count = 0;

	while (ifstream >> number) {
	  total_count++;
	  if (write_to_a_file) {
		if (a_number > number) {
		  b_count++;
		  b_number = number;
		  b_ofstream << b_number << std::endl;
		  write_to_a_file = false;
		  stream_swap_count++;
		} else {
		  a_count++;
		  a_number = number;
		  a_ofstream << a_number << std::endl;
		}
	  } else {
		stream_was_swapped = true;
		if (b_number > number) {
		  a_count++;
		  a_number = number;
		  a_ofstream << a_number << std::endl;
		  write_to_a_file = true;
		  stream_swap_count++;
		} else {
		  b_count++;
		  b_number = number;
		  b_ofstream << b_number << std::endl;
		}
	  }
	}

	std::cout << "TOTAL: " << total_count << " [A: " << a_count << " " << " B: " << b_count << " = " << (a_count + b_count) << " ] SWP CNT: " << stream_swap_count << std::endl;

	ifstream.close();
	a_ofstream.flush();
	a_ofstream.close();

	b_ofstream.flush();
	b_ofstream.close();

	return stream_was_swapped;
  }

  void merge_files(const std::string &in_file_path) {
	std::ifstream a_ifstream;
	a_ifstream.open(a_file);
	std::ifstream b_ifstream;
	b_ifstream.open(b_file);

	//Result of merging a and b files
	std::ofstream c_ofstream;
	c_ofstream.open(in_file_path);

	int a_number = std::numeric_limits<int>::min(), b_number = std::numeric_limits<int>::min();
	bool no_a_element = !(a_ifstream >> a_number);
	bool no_b_element = !(b_ifstream >> b_number);

	while (true) {
	  if (no_a_element && no_b_element)
		break;
	  if (!no_a_element && !no_b_element) {
		if (a_number <= b_number) {
		  c_ofstream << a_number << std::endl;
		  no_a_element = !(a_ifstream >> a_number);
		} else {
		  c_ofstream << b_number << std::endl;
		  no_b_element = !(b_ifstream >> b_number);
		}
	  } else if (!no_a_element) {
		c_ofstream << a_number << std::endl;
		no_a_element = !(a_ifstream >> a_number);
	  } else {
		c_ofstream << b_number << std::endl;
		no_b_element = !(b_ifstream >> b_number);
	  }
	}

	if (a_ifstream.is_open())
		a_ifstream.close();

	if (a_ifstream.is_open())
	  a_ifstream.close();

	c_ofstream.flush();
	c_ofstream.close();
  }

 private:
  const std::string a_file;
  const std::string b_file;

};