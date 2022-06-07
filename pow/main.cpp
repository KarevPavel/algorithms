//
// Created by yacopsae on 11/02/22.
//

#include "cmath"
#include "iomanip"
#include "iostream"
#include <pow.hpp>

template <typename T>
void print_2d_array(T ** matrix, int height, int weight) {
  std::cout << "2D Array:\n";
  for (int i = 0; i < height; i++) {
	std::cout << "| ";
	for (int j = 0; j < weight; j++) {
	  std::cout << std::setw(2);
	  if(matrix[j] != nullptr)
	    std::cout << matrix[j][i];
	  else
	    std::cout << "NPE";
	  std::cout << "  ";
	}
	std::cout << "|\n";
  }
}

int main() {
/*
  Utils::print_exec_time_and_result("Pow iterative", &Pow::iterative, 2, 20);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 2, 20);
  Utils::print_exec_time_and_result<long double>("Std::pow", &Pow::throughMultiplication, 1.125, 128);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 1.125, 128);
  Utils::print_exec_time_and_result<long long>("Std::pow", &Pow::throughMultiplication, 2, 100);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 2, 100);
*/
  //std::string str = {'4', '1', '2', '3', '4', '5', '6', '9', '8', '0', '3'}

}
