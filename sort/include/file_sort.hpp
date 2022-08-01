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
#include <stdio.h>

template <typename T>
class FileSort {
 public:
  FileSort(ArraySort<T> *array_sort,
		   std::string &output_dir);
  ~FileSort();

  void file_sort(std::string path,
				 int batch_size);

 private:
  int split_file(const std::string &path,
				 int batch_size);

  int *merge_files(int batch_size,
				   const std::string &path_a,
				   const std::string &path_b);

  void create_result(int file_counter);

  ArraySort<T> *_sort;
  const std::string &sort_result_path;
};

template <typename T>
FileSort<T>::FileSort(ArraySort<T> *array_sort,
				   std::string &sort_result_path) : sort_result_path(sort_result_path), _sort(array_sort) {}

template <typename T>
FileSort<T>::~FileSort() {
  delete this->_sort;
}

/**
 *
 * @param ifstream Стрим неотсоритованного файла с числами
 * @param batch_size Максимальный размер "пачки" (файл разделится на пачки batch_size/2,
 * Для того, что бы при слиянии файлов не превысить этот размер
 * @return Возвращает количество созданных файлов
 */
template <typename T>
int FileSort<T>::split_file(const std::string &file_path, int batch_size) {
  std::ifstream ifstream;
  std::ofstream ofstream;

  ifstream.open(file_path);
  if (!ifstream)
	throw std::runtime_error("Cannot open file!");

  long number;
  int index, file_name_counter;
  index = file_name_counter = 0;
  int length = batch_size / 2;

  long *numbers = new long[length];

  while (true) {
	bool no_element = !(ifstream >> number);
	if (!no_element)
	  numbers[index++] = number;

	if (index > length || (no_element && index > 0)) {
	  this->_sort->sort(numbers, index);
	  std::string file = sort_result_path + std::to_string(file_name_counter++);
	  ofstream.open(file);
	  if (!ofstream)
		throw std::runtime_error("Cannot open file!");
	  for (int i = 0; i < index && (&numbers[i]) != nullptr; i++)
		if (i == 0)
		  ofstream << numbers[i];
		else
		  ofstream << '\n' << numbers[i];

	  ofstream.flush();
	  ofstream.close();
	  index = 0;
	  //delete[] numbers;
	  numbers = new long[length]{NULL};
	}
	if (no_element) {
	  delete[] numbers;
	  break;
	}
  }
  return file_name_counter;
}

template <typename T>
int *FileSort<T>::merge_files(int batch_size,
						   const std::string &path_a,
						   const std::string &path_b) {

  std::ifstream a_ifstream; // std::ifstream j_ifstream;
  std::ifstream b_ifstream; // std::ifstream i_ifstream;

  a_ifstream.open(path_a);
  if (!a_ifstream)
	throw std::runtime_error("Cannot open i_file!" + path_a);

  b_ifstream.open(path_b);
  if (!b_ifstream)
	throw std::runtime_error("Cannot open j_file! " + path_b);

  int *merge_result = new int[batch_size];

  int index = 0;
  int a_number, b_number;
  bool no_a_element = !(a_ifstream >> a_number);
  bool no_b_element = !(b_ifstream >> b_number);

  while (true) {
	if (no_a_element && no_b_element)
	  break;

	if (!no_a_element && !no_b_element) {
	  if (a_number <= b_number) {
		merge_result[index++] = a_number;
		no_a_element = !(a_ifstream >> a_number);
	  } else {
		merge_result[index++] = b_number;
		no_b_element = !(b_ifstream >> b_number);
	  }
	} else if (!no_a_element) {
	  merge_result[index++] = a_number;
	  no_a_element = !(a_ifstream >> a_number);
	} else {
	  merge_result[index++] = b_number;
	  no_b_element = !(b_ifstream >> b_number);
	}
  }

  if (a_ifstream.is_open())
	a_ifstream.close();
  a_ifstream.clear();

  if (b_ifstream.is_open())
	b_ifstream.close();
  b_ifstream.clear();

  remove(path_a.c_str());
  remove(path_b.c_str());

  return merge_result;
}
template <typename T>
void FileSort<T>::file_sort(std::string in_file_path,
						 int batch_size) {

  int file_name_counter = split_file(in_file_path, batch_size);
  std::string a_file, b_file;
  for (int sorted_file_name = 0; sorted_file_name < file_name_counter;) {
	a_file = sort_result_path + std::to_string(sorted_file_name);
	for (int next_file_name = sorted_file_name + 1; next_file_name < file_name_counter; next_file_name++) {
	  b_file = sort_result_path + std::to_string(next_file_name);
	  int *merge_result = merge_files(batch_size, a_file, b_file);
	  int m = batch_size / 2;
	  int *first_part = Utils::array_part(merge_result, 0, m);
	  int *second_part = Utils::array_part(merge_result, m, batch_size - 1);
	  delete merge_result;
	  Utils::overwrite_file(a_file, first_part, m);
	  Utils::overwrite_file(b_file, second_part, m);
	}
	sorted_file_name++;
  }

  create_result(file_name_counter);
}
template <typename T>
void FileSort<T>::create_result(int file_counter) {
  std::ifstream ifstream;
  std::ofstream ofstream;

  ofstream.open(sort_result_path + "MAIN_RESULT");
  for (int i = 0; i < file_counter; i++) {
	std::string file = sort_result_path + std::to_string(i);
	ifstream.open(file);
	if (!ifstream)
	  throw std::runtime_error("Cannot open file!");
	int number;
	while (ifstream >> number)
	  ofstream << number << std::endl;

	ifstream.close();
	ifstream.clear();
	remove(file.c_str());
  }
}