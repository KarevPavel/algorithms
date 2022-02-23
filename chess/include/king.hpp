#pragma once

namespace King {
using ul = unsigned long;
unsigned long get_moves(int position);
}

unsigned long King::get_moves(int position) {
  ul K = 1ul << position;
  ul no_A = 0xfefefefefefefefe;
  ul no_H = 0x7f7f7f7f7f7f7f7f;
  ul k_no_A = K & no_A;
  ul k_no_H = K & no_H;
  return (k_no_A << 7) | (k_no_A << 8) |
	  (k_no_H << 9) | (k_no_A >> 1) |
	  (k_no_H << 1) | (k_no_A >> 9) |
	  (k_no_A >> 8) | (k_no_H >> 7);
}