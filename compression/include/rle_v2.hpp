//
// Created by yacopsae on 18/05/2022.
//
#pragma once

#include <iostream>
#include <limits>
#include "factor_array.hpp"

class RLEv2 {
 public:
  explicit RLEv2(std::istream &istream):istream(istream) {}

  void compress(std::ostream &output) {
	char ch, prev;
	u_int8_t eq_counter = 0;
	int8_t diff_counter = 0;
	auto list = FactorArray<char>();

	while (istream >> ch) {
	  if (eq_counter == std::numeric_limits<u_int8_t>::max()) {
		output << (int)eq_counter << prev;
		eq_counter = 0;
	  }
	  if (diff_counter == std::numeric_limits<int8_t>::max() || diff_counter == std::numeric_limits<int8_t>::min()) {
		output << (int)diff_counter << prev;
		diff_counter = 0;
	  }

	  if (ch == prev) {
		if (diff_counter < 0) {
		  diff_counter++;
		  output << (int)diff_counter << prev;
		  diff_counter = 0;
		  prev = ch;
		  continue;
		}
		eq_counter++;
	  } else {
		diff_counter--;
	    if (eq_counter > 1) {
		  eq_counter--;
		  output << (int)eq_counter << prev;
		  eq_counter = 0;
		  prev = ch;
		  continue;
	    }
		list.put(ch);
		eq_counter = 0;
		prev = ch;
	  }
	}
	if (eq_counter > 0)
	  output << (int)eq_counter << prev;
	if (diff_counter < 0) {
	  output << (int)diff_counter;
	  for (int i = 0; i < list.size(); i++)
		output << list.get(i);
	}
  }

 private:
  std::istream &istream;

};