//
// Created by yacopsae on 12/04/22.
//

#include <iostream>
#include <demucron.hpp>
#include <kosaraju.hpp>

int main() {
/*
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
*/


  auto * arr2 = new int * [4]{
	  new int[4]{0, 1, 0, 1},
	  new int[4]{0, 0, 1, 0},
	  new int[4]{1, 0, 0, 0},
	  new int[4]{0, 0, 1, 0}
  };
  Kosaraju kosaraju {arr2, 4};
  kosaraju.calc();
}
