//
// Created by yacopsae on 29/06/2022.
//

#pragma once

#include "iostream"

int scd(int a, int b) {
  if (b == 0)
	return a;
  return scd(b, a % b);
}


std::string pea(std::istream &cin) {
  char ch, idx = 0;
  int a, b, c, d, number = 0;
  int *array[3]{&a, &b, &c};

  while (cin >> ch)
	if (ch == '/' || ch == '+') {
	  *array[idx++] = number;
	  number = 0;
	} else if (number == 0)
	  number = ch - '0';
	else
	  number = number * 10 + (ch - '0');

  d = number;

  int div = b * d;
  int sum = a * d + c * b;
  int _scd = scd(div, sum);
  return std::to_string(sum/_scd) + "/" + std::to_string(div/ _scd);
}
