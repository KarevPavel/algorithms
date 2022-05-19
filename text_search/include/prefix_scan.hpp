//
// Created by yacopsae on 13/05/2022.
//

#pragma once

#include <string>

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