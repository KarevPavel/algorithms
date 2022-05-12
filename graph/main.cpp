//
// Created by yacopsae on 12/04/22.
//

#include <iostream>
#include <demucron.hpp>
#include <kosaraju.hpp>

int main() {
  auto *arr = new int *[6]{
	  new int[6]{0, 0, 0, 0, 0, 1},
	  new int[6]{1, 0, 0, 1, 1, 1},
	  new int[6]{0, 1, 0, 0, 1, 0},
	  new int[6]{1, 0, 0, 0, 0, 0},
	  new int[6]{0, 0, 0, 0, 0, 1},
	  new int[6]{0, 0, 0, 0, 0, 0}
  };
  Demucron demucron{arr, 6};
  auto result = demucron.sort();

  for (int lvl = 0; lvl < 6; lvl++) {
    if (result[lvl] != nullptr ) {
	  std::cout << "LVL: " << lvl << std::endl;
	  for (int idx = 0; idx < result[lvl]->size(); idx++)
		std::cout << "\tVERTEX INDX: " << result[lvl]->get(idx) << std::endl;
	}
  }


  //OUTPUT
  //COMPONENT №1 [ 0 4 ]
  //COMPONENT №2 [ 2 3 7 6 ]
  auto *arr3 = new int *[8]{
	  new int[8]{0, 1, 0, 0, 0, 0, 0, 0},
	  new int[8]{0, 0, 1, 0, 1, 1, 0, 0},
	  new int[8]{0, 0, 0, 1, 0, 0, 0, 0},
	  new int[8]{0, 0, 1, 0, 0, 0, 0, 1},
	  new int[8]{1, 0, 0, 0, 0, 1, 0, 0},
	  new int[8]{0, 0, 0, 0, 0, 0, 1, 0},
	  new int[8]{0, 0, 1, 0, 0, 1, 0, 1},
	  new int[8]{0, 0, 0, 1, 0, 0, 0, 0}
  };
  Kosaraju kosaraju {arr3, 8};
  auto kosaraju_result = kosaraju.calc();
  for (int i = 0; i < kosaraju_result.size(); i ++) {
    std::cout << "COMPONENT №" << (i + 1) << " [ ";
    for (int j = 0; j < kosaraju_result.get(i)->size(); j++) {
      std::cout << kosaraju_result.get(i)->get(j) << " ";
    }
    std::cout << "]" << std::endl;
  }
}
