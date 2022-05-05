//
// Created by yacopsae on 28/02/22.
//

#pragma once
#include "array.hpp"
#include <utility>
#include <cstring>

template<typename T>
class VectorArray : public Array<T> {
 public:
  explicit VectorArray(int buffer_size);

  T get(int index) override;
  void put(T item) override;
  void put(int index, T item) override;
  int size() override;
  void resize();
  void clean();

 private:
  size_t _capacity;
  size_t _length;
  size_t _buffer_size;
  T * _array;
};

template<typename T>
VectorArray<T>::VectorArray(int buffer_size) :
	_capacity(buffer_size),
	_length(0),
	_array(new int[buffer_size]),
	_buffer_size(buffer_size) {}

template<typename T>
void VectorArray<T>::put(T item) {
  if (_length == _capacity)
	resize();
  _array[_length++] = item;
}

template<typename T>
void VectorArray<T>::resize() {
  _capacity += _buffer_size;
  auto new_array = new int[_capacity];
  std::memcpy(new_array, _array, _length);
  delete[] _array;
  _array = nullptr;
  _array = new_array;
}

template<typename T>
T VectorArray<T>::get(int index) {
  return _array[index];
}

template<typename T>
void VectorArray<T>::put(int index, T item) {

}

template<typename T>
int VectorArray<T>::size() {
  return _length;
}

template<typename T>
void VectorArray<T>::clean() {
  delete[] _array;
  _array = nullptr;
  _capacity = _buffer_size;
  _array = new int[_buffer_size];
}
