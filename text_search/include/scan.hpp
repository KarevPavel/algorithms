//
// Created by yacopsae on 30/04/2022.
//

#pragma once
#include <string>
#include "utils.hpp"

namespace Fullscan {
  bool found(const std::string& text, const std::string& pattern) {
	for (char t : text)
	  for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] != t)
		  continue;
		else if ((i + 1) == pattern.length() && pattern[i] == t)
		  return true;
	  }
	return false;
  }
}

#define SHIFT_SIZE 128
namespace PrefixScan {

	unsigned short * create_shift(const std::string& pattern) {
	  auto *shift = new unsigned short[SHIFT_SIZE];
	  for (int i = 0; i < SHIFT_SIZE; i++)
		shift[i] = pattern.length();
	  for (char p : pattern)
		shift[p] = 1;
	  return shift;
	}

	bool found(const std::string& text, const std::string& pattern) {
	  auto *shift = create_shift(pattern);
	  for (int t = 0; t < text.length() - pattern.length();) {
		int p = pattern.length() - 1;
		while (p >= 0 && text[t + p] == pattern[p])
		  p--;
		if (p < 0)
		  return true;
		t += shift[text[t + pattern.length() - 1]];
	  }
	  return false;
	}
}
namespace SuffixScan {
  unsigned short * create_shift(const std::string& pattern) {
	auto *shift = new unsigned short[SHIFT_SIZE];
	for (int i = 0; i < SHIFT_SIZE; i++)
	  shift[i] = pattern.length();
	for (char p : pattern)
	  shift[p] = pattern.length() - p - 1;
	return shift;
  }

  bool found(const std::string& text, const std::string& pattern) {
	auto *shift = create_shift(pattern);
	for (int t = 0; t < text.length() - pattern.length();) {
	  int p = pattern.length() - 1;
	  while (p >= 0 && text[t + p] == pattern[p])
		p--;
	  if (p < 0)
		return true;
	  t += shift[text[t + pattern.length() - 1]];
	}
	return false;
  }
}

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