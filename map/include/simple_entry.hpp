//
// Created by yacopsae on 31/03/22.
//

#pragma once

#include "map.hpp"
#include "deletable.hpp"

template<typename K, typename V>
class SimpleEntry {
 public:
  SimpleEntry() = default;
  SimpleEntry(K key, V value) : _key(key), _value(value) {}

  K key() {
	return _key;
  }

  V value() {
	return _value;
  }

  void value(V value) {
	this->_value = value;
  }

 private:
  K _key;
  V _value;
};
