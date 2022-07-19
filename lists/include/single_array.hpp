//
// Created by yacopsae on 25/02/22.
//

#pragma once

#include "array.hpp"
#include <utility>
#include <cstring>

template<typename T>
class SingleArray : public Array<T> {
 public:
  explicit SingleArray() :
	  _size(0),
	  array(new int[0]) {}

  T get(int index) override {
	return array[index];
  }

  void put(T item) override {
    resize();
	this->array[size() - 1] = item;
  }

  void put(int index, T item) override {

  }

  int size() override {
	return _size;
  }

  void resize() {
	int *new_array = new int[++_size];
	std::memcpy(new_array, array, _size * sizeof(T));
	delete[] array;
	array = new_array;
  }

  void clean() {
	delete[] array;
	_size = 0;
	array = new int[0];
  }

 private:
  size_t _size;
  T *array;
};
