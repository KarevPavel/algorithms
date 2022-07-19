//
// Created by yacopsae on 19/07/2022.
//

#pragma once

#include "tree.hpp"

template<typename T>
class RandomTree : public Tree<T> {
 public:
  void insert(T) override;
  bool search(T) override;
  void remove(T) override;

};