//
// Created by yacopsae on 11/02/22.
//

#pragma once

#include "cmath"

namespace Pow {
 long double iterative(int a, int pow);
 long long throughMultiplication(int a, int pow);
 long double throughMultiplication(double a, int pow);
 bool isInteger(long double number);
};

inline long double Pow::iterative(int a, int pow) {
  long double result = a;
  for (int i = 2; i <= pow; i++)
	result *= a;
  return result;
}

inline long long Pow::throughMultiplication(int a, int pow) {
  long double _2Pow = log2l(pow);
  long long _2PowRounded = std::llround(log2l(pow));

  long long result = a;
  for (int i = 1; i <= _2PowRounded; i++) {
	result *= result;
  }

  if (!isInteger(_2Pow)) {
	long long additionalMultiplication = pow - std::pow(2, _2PowRounded);
	for (int i = 1; i <= additionalMultiplication; i++) {
	  result *= a;
	}
  }
  return result;
}

inline long double Pow::throughMultiplication(double a, int pow) {
  long double _2Pow = log2l(pow);
  long long _2PowRounded = std::llround(log2l(pow));

  long double result = a;
  for (int i = 1; i <= _2Pow; i++) {
	result *= result;
  }

  if (!isInteger(_2Pow)) {
	long long additionalMultiplication = pow - _2PowRounded;
	for (int i = 1; i <= additionalMultiplication; i++) {
	  a *= a;
	}
	result += a;
  }

  return result;
}

/*
inline long long Pow::throughMulti() {

}
*/

inline bool Pow::isInteger(long double number) {
  bool test = (number -= (int)number) > 0;

  return (number -= (int)number) == 0;
}
