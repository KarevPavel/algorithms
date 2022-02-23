#include "iostream"
#include "knight.hpp"
#include "king.hpp"
#include "bits.hpp"

int main() {
  std::cout << King::get_moves(63) << std::endl;
  std::cout << Bits::popcnt(King::get_moves(63)) << std::endl;
  std::cout << Bits::popcnt2(King::get_moves(63)) << std::endl;

  std::cout << Knight::get_moves(63) << std::endl;
  std::cout << Bits::popcnt(Knight::get_moves(63)) << std::endl;
  std::cout << Bits::popcnt2(Knight::get_moves(63)) << std::endl;



}
