//
// Created by yacopsae on 31/03/22.
//

#pragma once
#include "simple_entry.hpp"
#include "deletable.hpp"

template<typename K, typename V>
class DeletableEntry: public SimpleEntry<K,V>, public Deletable {
 public:
  DeletableEntry() = default;
  DeletableEntry(DeletableEntry&) = default;
  DeletableEntry(K key, V value) : SimpleEntry<K,V>(key, value) {}
};