//
// Created by yacopsae on 18/05/2022.
//
#pragma once

#include <iostream>
#include <limits>
#include <cstdio>


class RLE {
 public:
  explicit RLE(std::istream &istream):istream(istream) {}

  void compress(std::ostream &output) {
	char ch, prev;
	u_int8_t counter = 0;

	while (istream >> ch) {
	  if (counter == std::numeric_limits<u_int8_t>::max()) {
		output << (int)counter << prev;
		counter = 1;
	  }
	  if (ch == prev) {
		counter++;
	  } else {
	    if (counter > 0) {
		  output << (int)counter << prev;
		}
		counter = 1;
		prev = ch;
	  }
	}
	if (counter > 0)
	  output << (int)counter << prev;
  }

 private:
  std::istream &istream;
};