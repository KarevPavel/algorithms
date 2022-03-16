//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include <string>
#include <fstream>

class ArraySort {
 public:
  virtual ~ArraySort() = default;
  virtual void sort(long *array, size_t length) = 0;
};