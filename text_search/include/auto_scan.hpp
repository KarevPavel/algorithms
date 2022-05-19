//
// Created by yacopsae on 17/05/2022.
//

#pragma once

#include "string"

#define a 97
#define z 122
const static char *create_alhpabet() {
  char *result = new char[z - a + 1];
  for (char ch = a, i = 0; ch <= z; ch++, i++)
	result[i] = ch;
  return result;
}

static const char *alphabet = create_alhpabet();

class Auto {
 private:
  int **_shift;
  std::string _pattern;

 public:
  void create_shifts(const std::string &pattern) {
	int alphabet_size = z - a + 1;
	_shift = new int *[pattern.length()];
	this->_pattern = pattern;
	for (int i = 0; i < pattern.length(); i++)
	  _shift[i] = new int[alphabet_size];

	for (int q = 0; q < pattern.length(); q++)
	  for (int i = 0; i < alphabet_size; i++) {
		char ch = alphabet[i];
		std::string line = pattern.substr(0, q) + ch;
		int k = q + 1;
		while (line.substr(line.length() - k) != pattern.substr(0, k))
		  k--;
		_shift[q][ch - alphabet[0]] = k;
	  }
  }

  int search(std::string text) {
    int q = 0;
    for (int i = 0; i < text.length(); i++) {
  		q = _shift[q][text[i] - alphabet[0]];
  		if (q == _pattern.length())
		  return i - _pattern.length() + 1;
    }
	return -1;
  }

};
