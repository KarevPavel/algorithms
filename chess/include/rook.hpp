//
// Created by yacopsae on 23/02/22.
//

#pragma once

namespace Rook {
  using ul = unsigned long;
  unsigned long get_moves(int position);
};

unsigned long Rook::get_moves(int position) {
  ul r = 1ul << position;
  ul x = 0xff;
  ul y = 0x101010101010101;
  auto row = position / 8;
  auto column = position - (row * 8);
  return ((y << column) | (x << (row * 8))) ^ r; // | (x >> column);
}



