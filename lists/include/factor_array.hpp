//
// Created by yacopsae on 28/02/22.
//

#pragma once

#include "array.hpp"
#include <utility>
#include <cstring>

template<typename T>
class FactorArray : public Array<T> {
 public:
  FactorArray();
  explicit FactorArray(int factor);

  T get(int index) override;
  void put(T item) override;
  void put(int index, T item) override;
  int size() override;
  void resize();
  void clean();

 private:
  size_t _capacity;
  size_t _length;
  size_t _factor;
  T * _array;
};

template<typename T>
FactorArray<T>::FactorArray() :
	_capacity(10),
	_length(0),
	_array(new T[_capacity]),
	_factor(10) { }

template<typename T>
FactorArray<T>::FactorArray(int factor) :
	_capacity(10),
	_length(0),
	_array(new T[_capacity]),
	_factor(factor) { }

template<typename T>
void FactorArray<T>::put(T item) {
  if (_length == _capacity)
	resize();
  _array[_length++] = item;
}

template<typename T>
void FactorArray<T>::resize() {
  _capacity *= _factor;
  auto new_array = new T[_capacity];
  std::memcpy(new_array, _array, _length);
  delete[] _array;
  _array = nullptr;
  _array = new_array;
}

template<typename T>
T FactorArray<T>::get(int index) {
  return _array[index];
}

template<typename T>
void FactorArray<T>::put(int index, T item) {

}

template<typename T>
int FactorArray<T>::size() {
  return _length;
}

template<typename T>
void FactorArray<T>::clean() {
  delete[] _array;
  _array = nullptr;
  _capacity = 10;
  _array = new T[10];
}
