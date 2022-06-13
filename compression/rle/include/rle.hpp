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

  static void compress_v2(std::istream &istream, std::ostream &output) {
	char c_byte, prev_byte;
	int8_t counter = 0;
	while(istream.get(c_byte)) {
	//while (istream.read(&c_byte, sizeof(c_byte))) {
	  if (counter == std::numeric_limits<int8_t>::max()) {
		output << counter << prev_byte;
		counter = 1;
	  }
	  if (c_byte == prev_byte) {
		counter++;
	  } else {
		if (counter > 0) {
		  output << counter;
		  output << prev_byte;
		}
		counter = 1;
		prev_byte = c_byte;
	  }
	}
	if (counter > 0)
	  output << counter << prev_byte;
  }

  static void decompress_V2(std::istream &istream, std::ostream &output) {
	char byte;
	int8_t count = 0;
	bool expect_number = true;
	while (istream.get(byte)) {
	  if (expect_number) {
		count = (int8_t) byte;
		expect_number = false;
	  } else {
		for (int8_t i = 0; i < count; i++)
		  output << byte;
		count = 0;
		expect_number = true;
	  }
	}
  }

/**
 * DELETE!!!!!!!!!!!!!
 * DELETE!!!!!!!!!!!!!
 * DELETE!!!!!!!!!!!!!
 * DELETE!!!!!!!!!!!!!
 * DELETE!!!!!!!!!!!!!
 *
 */
  static void compress(std::istream &istream, std::ostream &output) {
	char ch, prev;
	uint32_t counter = 0;
	while (istream.get(ch)) {
	  if (counter == std::numeric_limits<u_int8_t>::max()) {
		output << counter << prev;
		counter = 1;
	  }
	  if (ch == prev) {
		counter++;
	  } else {
		if (counter > 0) {
		  output << counter;
		  output << prev;
		}
		counter = 1;
		prev = ch;
	  }
	}
	if (counter > 0)
	  output << counter << prev;
  }

  static void decompress(std::istream &istream, std::ostream &output) {
	char ch;
	uint8_t count = 0;
	while (istream.get(ch)) {
	  if (!std::isalnum(ch) && std::iscntrl(ch) == 2) {
		if (count > 0)
		  count = count * 10 + ch;
		else
		  count = ch;
	  } else {
		for (uint8_t i = 0; i < count; i++)
		  output << ch;
		count = 0;
	  }
	}
  }
};