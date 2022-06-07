//
// Created by yacopsae on 02/06/2022.
//

#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <shed.hpp>
#include "digital_fir.hpp"
#include "_58.hpp"
#include "islands.hpp"

template <typename T>
void print_2d_array(T ** matrix, int height, int weight) {
  std::cout << "2D Array:\n";
  for (int i = 0; i < height; i++) {
	std::cout << "| ";
	for (int j = 0; j < weight; j++) {
	  std::cout << std::setw(2) << matrix[i][j] << "  ";
	}
	std::cout << "|\n";
  }
}

void set_zeros(bool **, int, int);

int main() {
/*  std::cout << count(3) << std::endl;
  std::cout << count(4) << std::endl;
  std::cout << count(5) << std::endl;
  std::cout << count(6) << std::endl;
  std::cout << count(7) << std::endl;
  std::cout << count(75) << std::endl;*/


/*  std::istringstream cin{"4\n"
  "1 1 1 1\n"
  "0 1 0 1\n"
  "0 0 0 0\n"
  "1 0 1 1"};
  std::cout << islands_count(cin);*/

  std::istringstream cin2{
	  "4 3\n"
	  "0 0 0 0\n"
      "0 1 0 0\n"
	  "1 0 0 0\n"
  };

  shed_square_v2(cin2);
}


