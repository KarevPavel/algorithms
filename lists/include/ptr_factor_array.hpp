//
// Created by yacopsae on 09/06/2022.
//


#pragma once

#include "array.hpp"
#include <utility>
#include <cstring>

template<typename T>
class PtrFactorArray {
 public:
  PtrFactorArray();
  explicit PtrFactorArray(int factor);
  ~PtrFactorArray();

  T * get(int index);
  void put(T * item);
  void put(int index, T * item);
  void remove(T * item);
  int size();
  void resize();
  void clean();
  T * find(T * item);



 private:
  size_t _capacity;
  size_t _length;

  double _factor;
  T ** _array;
};

template<typename T>
T * PtrFactorArray<T>::find(T * item) {
  for (int i = 0; i < size(); i++)
	if (*get(i) == *item)
	  return get(i);
  return nullptr;
}
template<typename T>
void PtrFactorArray<T>::remove(T * item) {
  for (int i = 0; i < size(); i++) {
	auto element = get(i);
	if (*element == *item) {
	  delete _array[i];
	  for (int j = i; j < size() - 1; j++) {
		_array[j] = _array[j + 1];
	  }
	  break;
	}
  }
  _length--;
}

template<typename T>
PtrFactorArray<T>::PtrFactorArray() :
	_capacity(10),
	_length(0),
	_array(new T * [_capacity]),
	_factor(10.) { }

template<typename T>
PtrFactorArray<T>::PtrFactorArray(int factor) :
	_capacity(10),
	_length(0),
	_array(new T[_capacity]),
	_factor(factor) { }

template<typename T>
void PtrFactorArray<T>::put(T * item) {
  if (_length == _capacity)
	resize();
  _array[_length++] = item;
}

template<typename T>
void PtrFactorArray<T>::resize() {
  _capacity *= _factor;
  auto new_array = new T * [_capacity];
  std::memcpy(new_array, _array, _length);
  delete[] _array;
  _array = nullptr;
  _array = new_array;
}

template<typename T>
T * PtrFactorArray<T>::get(int index) {
  return _array[index];
}

template<typename T>
void PtrFactorArray<T>::put(int index, T * item) {

}

template<typename T>
int PtrFactorArray<T>::size() {
  return _length;
}

template<typename T>
void PtrFactorArray<T>::clean() {
  delete[] _array;
  _array = nullptr;
  _capacity = 10;
  _array = new T[10];
}
template<typename T>
PtrFactorArray<T>::~PtrFactorArray() {
  delete _array;
}
