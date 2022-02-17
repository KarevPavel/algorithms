//
// Created by yacopsae on 11/02/22.
//

#pragma once

#include <cmath>

#define PHI 1.61803398874989484820

namespace Fibonacci {
static long long recursive(long long N);
static long long golden_ratio(long long N);
static long long matrix(long long N);
static long long iterative(long long N);

struct Matrix {
  long long current[2][2];
  Matrix();

  void multiply();
  void print();
};
}

Fibonacci::Matrix::Matrix() : current{1, 1, 1, 0} {}

void Fibonacci::Matrix::print() {
  std::cout << std::endl;
  std::cout << "( " << current[0][0] << " | " << current[1][0] << " )" << std::endl;
  std::cout << "( " << current[0][1] << " | " << current[1][1] << " )" << std::endl;
  std::cout << std::endl;
}

void Fibonacci::Matrix::multiply() {
  //( a0, b0 )
  //( a1, b1 )
  auto a11 = current[0][0];
  auto a12 = current[0][1];
  auto a21 = current[1][0];
  auto a22 = current[1][1];
  current[0][0] = a11 * a11 + a12 * a21;
  current[0][1] = a11 * a12 + a12 * a22;
  current[1][0] = a21 * a11 + a22 * a21;
  current[1][1] = a21 * a12 + a22 * a22;
}


//O(2^N)
inline long long Fibonacci::recursive(long long N) {
  if (N <= 1) return N;
  return recursive(N - 1) + recursive(N - 2);
}

inline long long Fibonacci::golden_ratio(long long N) {
  return std::llround((std::pow(PHI, N) / std::sqrt(5)));
}

// O(LogN)
inline long long Fibonacci::matrix(long long N) {
  auto m = new Fibonacci::Matrix {};
  for (int i = 2; i <= N; i*=2) {
	m->multiply();
  }
  return m->current[0][0];
}

long long Fibonacci::iterative(long long N) {
  long long f[N + 2];
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i <= N; i++)
	f[i] = f[i - 1] + f[i - 2];
  return f[N];
}