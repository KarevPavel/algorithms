//
// Created by yacopsae on 31/03/22.
//
#pragma once

#include "map.hpp"

template<typename K, typename V>
class ChainBucket : public Bucket<K, V> {
 public:
  ChainBucket() = default;
  ChainBucket(K key, V value) : Bucket<K, V>(key, value) {}

 protected:
  Bucket<K, V> *next() override;
  void next(Bucket<K, V> *) override;
  bool has_next() override;

 private:
  Bucket<K, V> *_next;
};
template<typename K, typename V>
Bucket<K, V> *ChainBucket<K, V>::next() {
  return _next;
}
template<typename K, typename V>
void ChainBucket<K, V>::next(Bucket<K, V> *next) {
  this->_next = next;
}

template<typename K, typename V>
bool ChainBucket<K, V>::has_next() {
  return next();
}
