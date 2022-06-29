//
// Created by yacopsae on 02/06/2022.
//

#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "pea.hpp"
#include "digital_fir.hpp"
#include "_58.hpp"
#include "islands.hpp"
#include "shed_n^4.hpp"


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

  /*std::istringstream cin2{
	  "4 3\n"
	  "0 0 0 0\n"
      "0 1 0 0\n"
	  "1 0 0 0\n"
  };

  std::cout << shed_square(cin2) << std::endl;*/

  std::istringstream cin { "2/100+3/100" };
  std::cout << pea(cin);

}


