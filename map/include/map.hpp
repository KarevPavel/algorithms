//
// Created by yacopsae on 23/03/22.
//

#pragma once

template<typename K, typename V>
class Bucket {
 public:
  Bucket() = default;
  Bucket(K key, V value) : _key(key), _value(value) {}

 public:
  virtual Bucket *next() = 0;
  virtual void next(Bucket *) = 0;
  virtual bool has_next() = 0;

  K key() {
	return _key;
  }

  V value() {
	return _value;
  }

  void value(V value) {
	this->_value = value;
  }

 protected:
  K _key;
  V _value;
};

template<typename K, typename V>
class Map {
 public:
  virtual void put(K k, V v) = 0;
  virtual bool contains(K k) = 0;
  virtual void remove(K k) = 0;
  virtual Bucket<K, V> *get(K k) = 0;
 protected:
  virtual void rehash() = 0;
  virtual int hash(size_t hash_code) = 0;
  Bucket<K, V> **buckets;
};
