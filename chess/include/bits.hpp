//
// Created by yacopsae on 18/02/22.
//

#pragma once

namespace Bits {
using ul = unsigned long;
long popcnt(ul);
long popcnt2(ul);
}

long Bits::popcnt(ul mask) {
  int count = 0;
  while (mask > 0) {
    if ((mask & 1UL) == 1)
      count++;
    mask >>= 1;
  }
  return count;
}

long Bits::popcnt2(ul mask) {
  int count = 0;
  while (mask > 0) {
    count++;
    mask &= mask - 1;
  }
  return count;
}