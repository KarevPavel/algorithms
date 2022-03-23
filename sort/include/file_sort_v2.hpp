//
// Created by yacopsae on 18/03/22.
//

#pragma once

#include <string>

class MergeFileSort {
 public:
  MergeFileSort(std::string &output_dir);
  void file_sort(std::string in_file, std::size_t number_count);
  void mergeSort(std::string in_file, int l, int r);
 private:
  const std::string &output_dir;

};

MergeFileSort::MergeFileSort(std::string &output_dir): output_dir(output_dir) {}

void MergeFileSort::file_sort(std::string in_file, std::size_t number_count) {
  mergeSort(in_file, 0, number_count);
}

void MergeFileSort::mergeSort(std::string in_file, int l, int r) {
  if (l < r) {
	int m = l + (r - l) / 2;
	mergeSort(in_file, l, m);
	mergeSort(in_file, m + 1, r);
  }
}