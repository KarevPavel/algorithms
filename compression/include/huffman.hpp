//
// Created by yacopsae on 19/05/2022.
//

#pragma once
#include <iostream>
#include <limits>

class Huffman {
 public:
  explicit Huffman(std::istream &istream) : istream(istream) {

  }

 private:
  std::istream &istream;
};