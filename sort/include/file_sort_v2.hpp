//
// Created by yacopsae on 18/03/22.
//

#pragma once

#include <string>

class FileSort {
 public:
  FileSort(std::string &output_dir);

  void file_sort(std::string in_file, int batch_size);

 private:
  const std::string &output_dir;

};

FileSort::FileSort(std::string &output_dir)
: output_dir(output_dir) {}

void FileSort::file_sort(std::string in_file, int batch_size) {

}