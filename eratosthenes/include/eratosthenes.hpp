#pragma once

#include "math.h"

namespace Eratosthenes {

int simple(int right_border);

}

inline int Eratosthenes::simple(int right_border) {
  bool divs[right_border + 1];
  int count = 0;
  double sqrt = std::sqrt(right_border);
  for (int p = 2; p <= right_border; p++)
	if (!divs[p]) {
	  count++;
	  if (p <= sqrt)
		for (int j = p * p; j <= right_border; j += p) {
		  divs[j] = true;
		}
	}
  return count;
}