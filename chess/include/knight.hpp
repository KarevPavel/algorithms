
#pragma once

//Конь
namespace Knight {
  using ul = unsigned long;
  unsigned long get_moves(int position);
}


unsigned long Knight::get_moves(int position) {
  ul k = 1ul << position;
  ul k_no_a_b = k & 0xfcfcfcfcfcfcfcfc;
  ul k_no_g_h = k & 0x3f3f3f3f3f3f3f3f;
  ul k_no_a = k & 0xfefefefefefefefe;
  ul k_no_h = k & 0x7f7f7f7f7f7f7f7f;

  return (k_no_a_b << 6) | (k_no_a_b >> 10) | (k_no_g_h << 10) | (k_no_g_h >> 6) |
	  (k_no_a >> 17) | (k_no_h >> 15) | (k << 17) | (k << 15);
}