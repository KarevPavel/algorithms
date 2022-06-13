//
// Created by yacopsae on 25/02/22.
//

#pragma once

#include <iostream>

template <typename T>
class Array {
 public:
  virtual T get(int index) = 0;
  virtual void put(T item) = 0;
  virtual void put(int index, T item) = 0;
  virtual int size() = 0;
  virtual void clean() = 0;

  T find(T item) {
	for (int i = 0; i < size(); i++)
	  if (get(i) == item)
		return get(i);
	return nullptr;
  }

  bool contains(T item) {
    for (int i = 0; i < size(); i++)
      if (get(i) == item)
		return true;
	return false;
  }

  bool is_empty() {
	return size() == 0;
  }
};


