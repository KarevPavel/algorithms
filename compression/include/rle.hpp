//
// Created by yacopsae on 18/05/2022.
//
#pragma once

#include <iostream>
#include <limits>
#include <cstdio>
#include <cctype>

class RLE {
 public:



  static void compress(std::istream &istream, std::ostream &output) {
	char ch, prev;
	u_int8_t counter = 0;
	while (istream.get(ch)) {
	  if (counter == std::numeric_limits<u_int8_t>::max()) {
		output << (int)counter << prev;
		counter = 1;
	  }
	  if (ch == prev) {
		counter++;
	  } else {
		if (counter > 0) {
		  output << (int)counter;
		  output << prev;
		}
		counter = 1;
		prev = ch;
	  }
	}
	if (counter > 0)
	  output << (int)counter << prev;
  }

  static void decompress(std::istream &istream, std::ostream &output) {
	char ch;
	uint8_t count = 0;
	while (istream.get(ch)) {
	  if (std::isdigit(ch)) {
		if (count > 0)
		  count = count * 10 + (ch - '0');
		else
		  count = ch - '0';
	  } else {
		for (uint8_t i = 0; i < count; i++)
		  output << ch;
		count = 0;
	  }
	}
  }
};