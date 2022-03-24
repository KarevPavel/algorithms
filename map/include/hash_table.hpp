//
// Created by yacopsae on 23/03/22.
//

#pragma once

#include <iostream>
#include <functional>
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

#define INITIAL_SIZE 10
#define INITIAL_FACTOR 2
template<typename K, typename V>
class HashTable : public Map<K, V> {
 public:

  explicit HashTable(std::function<int(K)> hashcode_function) :
	  _factor(INITIAL_FACTOR),
	  _array_capacity(INITIAL_SIZE),
	  _array_length(0),
	  _hashcode_function(hashcode_function) {
	this->buckets = new Bucket<K, V> *[INITIAL_SIZE];
  }

  void put(K k, V v) override;
  bool contains(K k) override;
  void remove(K k) override;
  Bucket<K, V> *get(K k) override;
 protected:
  int hash(size_t hash_code) override;
  void rehash() override;

 private:
  int _factor;
  int _array_capacity;
  int _array_length;
  std::function<int(K)> _hashcode_function;
};

template<typename K, typename V>
void HashTable<K, V>::put(K k, V v) {
  auto hashCode = _hashcode_function(k);
  if (++this->_array_length > this->_array_capacity)
	this->rehash();
  auto idx = hash(hashCode);
  auto element = this->buckets[idx];
  auto *new_element = new ChainBucket<K, V>(k, v);
  if (!element)
	this->buckets[idx] = new_element;
  else {
	while (element) {
	  if (element->key() == new_element->key()) {
		element->value(v);
		return;
	  }
	  if (!element->has_next())
		break;
	  element = element->next();
	}
	element->next(new_element);
  }
}

template<typename K, typename V>
bool HashTable<K, V>::contains(K k) {
  int idx = hash(_hashcode_function(k));
  auto *bucket = this->buckets[idx];
  if (!bucket)
	return false;
  while (bucket)
	if (bucket->key() == k)
	  return true;
	else
	  bucket = bucket->next();
  return false;
}

template<typename K, typename V>
void HashTable<K, V>::remove(K k) {
  int idx = hash(_hashcode_function(k));
  auto *bucket = this->buckets[idx];
  if (bucket == nullptr)
	return;
  while (bucket != nullptr)
	if (bucket->key() == k) {
	  this->buckets[idx] = bucket->next();
	  delete bucket;
	  return;
	} else
	  bucket = bucket->next();
}

template<typename K, typename V>
void HashTable<K, V>::rehash() {
  auto *new_buckets = new Bucket<K, V> *[this->_array_length * this->_factor];
  for (int i = 0; i < this->_array_length; i++) {
	auto *element = this->buckets[i];
	if (!element)
	  return;
	new_buckets[hash(_hashcode_function(element->key()))] = element;
	for (auto *e = element->next(); e != nullptr; e = e->next()) {
	  int idx = hash(hash(_hashcode_function(e->key())));
	  if (new_buckets[idx] != nullptr)
		new_buckets[idx]->next(e);
	  else
		new_buckets[idx] = e;
	}
  }
  delete this->buckets;
  this->buckets = new_buckets;
}

template<typename K, typename V>
int HashTable<K, V>::hash(size_t hash_code) {
  return hash_code % this->_array_capacity;
}
template<typename K, typename V>
Bucket<K, V> *HashTable<K, V>::get(K k) {
  Bucket<K, V> *element = this->buckets[hash(_hashcode_function(k))];
  if (!element->has_next())
	return element;

  while (element->has_next())
	if (element->key() == k)
	  return element;
	else
	  element = element->next();

  return nullptr;
}
