//
// Created by yacopsae on 31/03/22.
//
#pragma once

#include "map.hpp"

template<typename K, typename V>
class ChainBucket : public SimpleEntry<K, V> {
 public:
  ChainBucket() = default;
  ChainBucket(K key, V value) : SimpleEntry<K, V>(key, value) {}

  ChainBucket<K, V> *next();
  void next(ChainBucket<K, V> *);
  bool has_next();

 private:
  ChainBucket<K, V> *_next;
};

template<typename K, typename V>
ChainBucket<K, V> *ChainBucket<K, V>::next() {
  return _next;
}
template<typename K, typename V>
void ChainBucket<K, V>::next(ChainBucket<K, V> *next) {
  this->_next = next;
}

template<typename K, typename V>
bool ChainBucket<K, V>::has_next() {
  return next();
}
