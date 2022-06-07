//
// Created by yacopsae on 02/06/2022.
//

#pragma once
#include "iostream"
#include "cmath"

using ul = unsigned long long;

ul count(int number) {
  if (number == 1)
	return 2;
  if (number == 2)
	return 2;

  ul _55 = 1,
  _58 = 1,
  _88 = 1,
  _85 = 1,
  tmp_55,
  tmp_58,
  tmp_88,
  tmp_85;

  /**
   * f55 = f58
   * f58 = f85 + f88
   * f85 = f55 + f58
   * f88 = f85
   */
  for (int i = 3; i <= number; i++) {
     tmp_55 = _58;
     tmp_58 = _85 + _88;
     tmp_85 = _55 + _58;
     tmp_88 = _85;
     _55 = tmp_55;
     _58 = tmp_58;
     _85 = tmp_85;
     _88 = tmp_88;
  }
  return _55 + _58 + _85 + _88;
}