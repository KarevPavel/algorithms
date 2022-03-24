//
// Created by yacopsae on 24/03/22.
//

#pragma once

#include "string"

namespace Hash {
  int simple_hash(const std::string &value) {
	int result = 0;
	for (char i : value)
	  result += (int)i;
	return result;
  }
}