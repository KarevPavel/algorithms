//
// Created by yacopsae on 17/05/2022.
//

#pragma once

#include <iostream>
#include "string"
#include "factor_array.hpp"

class Kmp {

 public:
  static int * create_slow(const std::string& pattern) {
	int * pi = new int[pattern.length() + 1] { 0 };
	for (int q = 0; q <= pattern.length(); q++) {
	  std::string line = pattern.substr(0, q);
	  for (int len = 0; len < q; len++)
		if (line.substr(0, len) == line.substr(line.length() - len))
		  pi[q] = len;
	}
	return pi;
  }

  static int * create_fast(std::string pattern) {
	int * pi = new int[pattern.length() + 1] { 0 };
	for (int q = 1; q < pattern.length(); q++) {
	  int len = pi[q];
	  while (len > 0 && pattern[len] != pattern[q])
		len = pi[len];
	  if (pattern[len] == pattern[q])
		len++;
	  pi[q + 1] = len;
	}
	return pi;
  }

  static Array<size_t> * find(const std::string & text, const std::string & pattern) {
	int *res = create_fast(pattern + '@' + text);
	size_t max = text.length() + pattern.length() + 1;
	size_t pattern_length = pattern.size();
	auto array = new FactorArray<size_t>();
	for (size_t i = pattern_length; i < max; i++) {
	  if (res[i] == pattern_length)
		array->put(i - 1 - 2 * pattern_length);
	}
	return array;
  }
};