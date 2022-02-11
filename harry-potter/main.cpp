#include <iostream>
#include "cmath"
#include <algorithm>

int main() {
  for (int x = 0; x < 25; x++) {
	for (int y = 0; y < 25; y++) {
	  if (log2(y) > x)
		std::cout << "#";
	  else
		std::cout << ".";
	}
	std::cout << std::endl;
  }
  return 0;
}


//2.  (x == y)
//3.  (x == 24 - y)
//4.  (x < 30 - y)
//5.  (x == y/2)
//6.  (x < 10 || y < 10)
//7.  (x > 15 && y > 15)
//8.  (x == 0 || y == 0)
//9.  (x  > y + 11 || x < y - 11) или (abs(x - y) > 11)
//10. (x < y && x >= y / 2)
//11. ((x > 0 && 23 % x == 0) || (y > 0 && 23 % y == 0))
//12.
//13. (x >= 20 - y && x <= 28 - y)
//14. (sqrt(x * y) < 10)
//15.
//16. (abs(x - 12) + abs(y - 12) < 10)
//17.
//18.
//19. (x * y == 0 || x == 24 || y == 24)
//20. ((x + y) % 2 == 0)
//21.
//22. ((x + y) % 3 == 0)
//23.
//24. (x - y == 0 || x + y == 24)
//25.

