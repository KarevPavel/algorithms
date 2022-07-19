//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include <string>
#include <fstream>

template <typename T>
class ArraySort {
 public:
  virtual ~ArraySort() = default;
  virtual void sort(T *array, size_t length) = 0;
};