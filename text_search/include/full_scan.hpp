//
// Created by yacopsae on 13/05/2022.
//

#pragma once

#include <string>

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