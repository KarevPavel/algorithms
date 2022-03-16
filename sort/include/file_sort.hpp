//
// Created by yacopsae on 15/03/22.
//

#pragma once

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "array_sort.hpp"

class FileSort {
 public:
  FileSort(ArraySort *array_sort,
		   std::string &output_dir);
  ~FileSort();

  void file_sort(std::string path,
				 char separator,
				 int batch_size);
 private:
  ArraySort *_sort;
  std::string &output_dir;
};

FileSort::FileSort(ArraySort *array_sort,
				   std::string &output_dir) : output_dir(output_dir), _sort(array_sort) {}

FileSort::~FileSort() {
  delete this->_sort;
}

void FileSort::file_sort(std::string path,
						 char separator,
						 int batch_size) {
  std::ifstream ifstream;
  ifstream.open(path);
  if (!ifstream)
	throw std::runtime_error("Cannot open file!");

  std::string temporary;
  long *numbers = new long[batch_size];
  long file_name_counter = 0;
  int index = 0;
  char ch;
  while (ifstream >> ch) {
	if (ch == separator) {
	  numbers[index++] = std::stoi(temporary);
	  std::cout << "index: " << index << std::endl;
	  temporary.clear();
	  continue;
	}

	temporary.push_back(ch);

	if (index >= batch_size - 1) {
	  this->_sort->sort(numbers, index);
	  std::ofstream ofstream;
	  ofstream.open(output_dir + std::to_string(file_name_counter++));
	  if (!ofstream)
		throw std::runtime_error("Cannot open file!");

	  for (int i = 0; i < index && (&numbers[i]) != nullptr; i++)
		ofstream << std::to_string(numbers[i]) + ",";

	  ofstream.flush();
	  ofstream.close();
	}
  }

  /*for (int i = 1, j = 0; i < file_name_counter; i += 2, j += 2) {
	std::ifstream file_i;
	file_i.open(output_dir + std::to_string(i));

	std::ifstream file_j;
	file_j.open(output_dir + std::to_string(j));

	if (!file_i || !file_j)
	  throw std::runtime_error("Cannot open files!");

	for (char ch_i = file_i.get(), ch_j = file_j.get();; file_i.get(ch_i), file_j.get(ch_j)) {
	  if (ch_i == separator && !file_i.eof()) {
		int number_i = std::stoi(temporary);
		temporary.clear();
		if (ch_j == separator && !file_j.eof()) {
		  int number_i = std::stoi(temporary);
		  int number_j = std::stoi(temporary);
		}

		continue;
	  }

	  temporary.push_back(ch_i);

	  break;
	}
  }*/
}