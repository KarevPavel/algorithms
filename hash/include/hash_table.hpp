//
// Created by yacopsae on 23/03/22.
//

#pragma once

#include <iostream>
#include "map.hpp"

template<typename K, typename V>
class ChainBucket : public Bucket<K, V> {
 public:
  ChainBucket() = default;
  ChainBucket(K key, V value) : Bucket<K, V>(key, value) {}

 protected:
  Bucket<K, V> *next() override;
  void add(Bucket<K, V> *) override;
};
template<typename K, typename V>
Bucket<K, V> *ChainBucket<K, V>::next() {
  return nullptr;
}
template<typename K, typename V>
void ChainBucket<K, V>::add(Bucket<K, V> *) {

}

#define INITIAL_SIZE 10
#define INITIAL_FACTOR 2
template<typename K, typename V>
class HashTable : public Map<K, V> {
 public:

  HashTable() :
	  _factor(INITIAL_FACTOR),
	  _array_capacity(INITIAL_SIZE),
	  _array_length(0) {
	this->buckets = new Bucket<K, V> *[INITIAL_SIZE];
  }

  void put(K k, V v) override;
  bool contains(K k) override;
  void remove(K k) override;
  Bucket<K, V> &get(K k) override;
 protected:
  int hash(size_t hash_code) override;
  void rehash() override;

 private:
  int _factor;
  int _array_capacity;
  int _array_length;
};

template<typename K, typename V>
void HashTable<K, V>::put(K k, V v) {
  auto hashCode = std::hash<K>()(k);
  if (++this->_array_length > this->_array_capacity) {
	this->rehash();
  }

  auto idx = hash(hashCode);
  auto element = this->buckets[idx];
  auto *new_element = new ChainBucket<K, V>(k, v);
  if (element == nullptr)
	this->buckets[idx] = new_element;
  else {
	if (element->next())
	  element->add(new_element);
  }
}

template<typename K, typename V>
bool HashTable<K, V>::contains(K k) {
  //TODO: Если лист имеет элементы нужно проходить по листу!!!
  return this->buckets[hash(std::hash<K>()(k))] != nullptr;
}

template<typename K, typename V>
void HashTable<K, V>::remove(K k) {
  int idx = hash(std::hash<K>()(k));
  auto *bucket = this->buckets[idx];
  if (bucket == nullptr)
	return;
  if (bucket->next() != nullptr)
	for (Bucket<K, V> *element = bucket->next(); element != nullptr; element = element->next())
	  if (element->key() == k)
		std::cout << "DELETE!" << std::endl;
}

template<typename K, typename V>
void HashTable<K, V>::rehash() {
  auto *new_buckets = new Bucket<K, V> * [this->_array_length * this->_factor];
  for (int i = 0; i < this->_array_length; i++) {
	auto *element = this->buckets[i];
	if (element == nullptr)
	  return;
	new_buckets[hash(std::hash<K>()(element->key()))] = element;
	for (auto *e = element->next(); e != nullptr; e = e->next()) {
	  int idx = hash(hash(std::hash<K>()(e->key())));
	  if (new_buckets[idx] != nullptr)
		new_buckets[idx]->add(e);
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
Bucket<K, V> &HashTable<K, V>::get(K k) {
  return *this->buckets[hash(std::hash<K>()(k))];
}
