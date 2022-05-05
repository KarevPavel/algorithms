//
// Created by yacopsae on 31/03/22.
//

#pragma once

#include "functional"
#include "map.hpp"
#include "simple_entry.hpp"
#include "deletable_entry.hpp"

/**
 * Хеш таблица с использованием открытой адресации
 * @tparam K тип ключи
 * @tparam V тип значения
 */

#define INITIAL_SIZE 10
#define INITIAL_FACTOR 2
template<typename K, typename V>
class HashTableWOA : public Map<K, V> {
 public:
  explicit HashTableWOA(std::function<int(K)> hashcode_function) :
	  _factor(INITIAL_FACTOR),
	  _array_capacity(INITIAL_SIZE),
	  _array_length(0),
	  _hashcode_function(hashcode_function) {
	this->buckets = new DeletableEntry<K, V> * [INITIAL_SIZE];
  }

  void put(K k, V v) override;
  bool contains(K k) override;
  void remove(K k) override;
  DeletableEntry<K, V> *get(K k) override;
  int hash(std::size_t hash_code) override;
  void rehash() override;

 private:
  std::function<int(K)> _hashcode_function;
  int _factor;
  int _array_capacity;
  int _array_length;
  DeletableEntry<K, V> **buckets;
};

template<typename K, typename V>
void HashTableWOA<K, V>::put(K k, V v) {
  auto hashCode = _hashcode_function(k);
  auto index = hash(hashCode);
  auto element = this->buckets[index];
  while (element != nullptr) {
	if (_array_capacity < ++index) {
	  this->rehash();
	} else {
	  element = this->buckets[index];
	}
  }
  this->_array_length++;
  this->buckets[index] = new DeletableEntry<K, V>(k, v);
}

template<typename K, typename V>
bool HashTableWOA<K, V>::contains(K k) {
  auto * result = get(k);
  if (result != nullptr)
	return !dynamic_cast<DeletableEntry<K, V>*>(result)->is_deleted();
  return false;
}

template<typename K, typename V>
void HashTableWOA<K, V>::remove(K k) {
  auto *entry = dynamic_cast<DeletableEntry<K, V>*>(get(k));
  if (entry != nullptr)
	entry->_delete();
}

template<typename K, typename V>
void HashTableWOA<K, V>::rehash() {
  std::cout << "BEFORE REHASH ";
  Utils::print_array(this->buckets, _array_capacity, std::cout);
  auto new_capacity = _array_capacity * this->_factor;
  auto *new_buckets = new DeletableEntry<K, V> *[new_capacity];
  for (int i = 0; i < this->_array_capacity; i++) {
	auto *element = this->buckets[i];
	if (!element)
	  continue;
	auto new_index = hash(_hashcode_function(element->key()));

	std::cout << "element " << element << " hash index: " << new_index << std::endl;

	std::cout << "element " << element << " hash index: " << new_index << std::endl;
	new_buckets[new_index] = element;
  }
  _array_capacity = new_capacity;
  //delete this->buckets;
  this->buckets = new_buckets;
  std::cout << "AFTER REHASH ";
  Utils::print_array(new_buckets, _array_capacity, std::cout);
  std::cout << "AFTER REHASH ";
}

template<typename K, typename V>
int HashTableWOA<K, V>::hash(std::size_t hash_code) {
  return hash_code % this->_array_capacity;
}

template<typename K, typename V>
DeletableEntry<K, V> *HashTableWOA<K, V>::get(K k) {
  int index = hash(_hashcode_function(k));
  auto *entry = this->buckets[index];
  auto last_index = this->_array_length - 1;
  int * deleted_index = nullptr;
  while (entry != nullptr && last_index < ++index && entry->key() != k) {
    if (entry->is_deleted()) {
	  deleted_index = new int {index};
	  continue;
    }
    if (deleted_index != nullptr) {
      auto * tmp = this->buckets[*deleted_index];
	  this->buckets[*deleted_index] = this->buckets[index];
	  this->buckets[index] = tmp;
    } else {
	  entry = this->buckets[index];
	}
  }
  return entry;
}
