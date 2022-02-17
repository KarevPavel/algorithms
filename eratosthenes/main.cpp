#include <utils.hpp>
#include <eratosthenes.hpp>

int main() {
  Utils::print_exec_time_and_result("Eratosthenes Simple", &Eratosthenes::simple, 50);
  Utils::print_exec_time_and_result("Eratosthenes Simple", &Eratosthenes::simple, 1000000);
}