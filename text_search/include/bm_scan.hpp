//
// Created by yacopsae on 13/05/2022.
//

#pragma once
#include <string>
#include "utils.hpp"

namespace BMScan {

unsigned int *pattern_shift(const std::string& pattern) {
  auto * shift = new unsigned int[pattern.length()];
  for (size_t length = 1; length < pattern.length(); length++) {
	auto next_p = pattern.substr(pattern.length() - length, length);
	for (size_t search = pattern.length() - length, p = length; search > 0 && p > 0; search--, p--) {
	  if (pattern[search] == pattern[p])
		shift[length] = search;
	}
  }
  Utils::print_array(shift, pattern.length(), std::cout);
  return shift;
}

bool found(const std::string &text, const std::string &pattern) {
  pattern_shift(pattern);
}
}