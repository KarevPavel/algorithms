//
// Created by yacopsae on 19/05/2022.
//

#pragma once
#include <iostream>
#include <limits>
#include "utils.hpp"
#include "counting_sort.hpp"

class Huffman {
 public:
  explicit Huffman(std::istream &istream) : istream(istream) {
  }

  #define a 65
  #define z 90
  void compress(std::ostream &output) {
    uint8_t alphabet_size = z - a;
    int alphabet[alphabet_size] = { 0 };
     char ch;
     while (istream >> ch)
       alphabet[ch - a]++;
     Utils::print_array(alphabet, alphabet_size, std::cout);

  }

 private:
  std::istream &istream;
};