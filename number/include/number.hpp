//
// Created by yacopsae on 15/02/22.
//

#pragma once

#include <algorithm>
#include <cmath>
#include <vector>
#include "list"

namespace PrimeNumber {
  namespace EnumOfDivisors {
	static long prime_count(long right_border);
	static long is_prime(long number);
  }

  namespace Optimized {
	static long prime_count(long right_border);
	static long is_prime(long number);
  }

  namespace PrimeCached {
  static long prime_count(long right_border);
  static long is_prime(long number, const long * primes);
  }
}

inline long PrimeNumber::EnumOfDivisors::prime_count(long right_border) {
  int primeCount = 0;
  for (int suspect = 2; suspect <= right_border; suspect++)
	if (is_prime(suspect))
	  primeCount++;
  return primeCount;
}

inline static long PrimeNumber::EnumOfDivisors::is_prime(long number) {
  long count = 0;
  for (int divisor = 1; divisor <= number; divisor++)
	if (number % divisor == 0)
	  count++;
  return count == 2;
}

inline long PrimeNumber::Optimized::prime_count(long right_border) {
  int primeCount = 0;
  for (int suspect = 2; suspect <= right_border; suspect++)
	if (is_prime(suspect))
	  primeCount++;
  return primeCount;
}

inline static long PrimeNumber::Optimized::is_prime(long number) {
  if (number == 2)
	return true;
  if (number % 2 == 0)
	return false;
  double sqrt = std::sqrt(number);
  for (int divisor = 2; divisor <= sqrt; divisor +=2)
	if (number % divisor == 0)
	  return false;
  return true;
}

inline long PrimeNumber::PrimeCached::prime_count(long right_border) {
  long * primes = new long[right_border / 2];
  int count = 0;
  primes[count++] = 2;
  for (int suspect = 3; suspect <= right_border; suspect++)
    if (is_prime(suspect, primes))
    	primes[count++] = suspect;
  return count;
}

inline static long PrimeNumber::PrimeCached::is_prime(long number, const long * primes) {
  long sqrt = std::sqrt(number);
  for (int i = 0; primes[i] <= sqrt; i++)
	if (number % primes[i] == 0)
	  return false;
  return true;
}