//
// Created by yacopsae on 13/02/22.
//

#pragma once

#include <chrono>
#include <string>
#include <iostream>

namespace Utils {

  template<typename R, typename ...Args>
  void print_exec_time_and_result(const std::string& test_name, R (*func)(Args...), Args && ...args);

  template <typename T>
  std::string to_string(T t1);

  template <typename T>
  std::string to_string(T t1, T t2);

  template <typename T, typename V>
  std::string to_string(T t, V v);

/*
  std::string duration_string(std::chrono::duration<long, std::ratio<1, 1000000000>> duration);

  template<typename R, typename T, typename V>
  void print_exec_time_and_result(const std::string& test_name, R (*func)(T, V), T t, V v);

  template<typename R, typename T>
  void print_exec_time_and_result(const std::string& test_name, R (*func)(T), T t);

  template<typename Functor>
  double execution_time_ns(Functor functor);

  template<typename Functor>
  std::chrono::duration<long, std::ratio<1, 1000000000>> execution_time(Functor functor);

*/

}

template <typename T>
inline std::string Utils::to_string(T t1) {
  return std::to_string(t1);
}

template <typename T>
inline std::string Utils::to_string(T t1, T t2) {
  return std::to_string(t1) + " " + std::to_string(t2);
}

template <typename T, typename V>
inline std::string Utils::to_string(T t, V v) {
  return std::to_string(t) + " " + std::to_string(v);
}

template<typename R, typename ...Args>
inline void Utils::print_exec_time_and_result(const std::string& test_name, R (*func)(Args...), Args && ...args) {
  auto start = std::chrono::steady_clock::now();
  std::cout << "--------" << test_name << "----------" << std::endl;
  std::cout << "Input Argument: " << to_string(std::forward<Args>(args)...) << std::endl;
  R result = func(std::forward<Args>(args)...);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  std::cout << "Result: " << std::to_string(result) << std::endl;
  std::cout << "Calc took: " << fp_ms.count() << " ms" << std::endl;
  std::cout << "____________________________" << std::endl << std::endl;
}


/*
template<typename R, typename T>
inline void Utils::print_exec_time_and_result(const std::string& test_name, R (*func)(T), T t) {
  auto start = std::chrono::steady_clock::now();
  std::cout << "--------" << test_name << "----------" << std::endl;
  std::cout << "Input Argument: " << std::to_string(t) << std::endl;
  R result = func(t);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  std::cout << "Result: " << std::to_string(result) << std::endl;
  std::cout << "Calc took: " << fp_ms.count() << " ms" << std::endl;
  std::cout << "____________________________" << std::endl << std::endl;
}


template<typename R, typename T, typename V>
inline void Utils::print_exec_time_and_result(const std::string& test_name, R (*func)(T, V), T t, V v) {
  auto start = std::chrono::steady_clock::now();
  std::cout << "--------" << test_name << "----------" << std::endl;
  std::cout << "Input Argument: " << std::to_string(t) << " " << to_string(v) << std::endl;
  R result = func(t, v);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  std::cout << "Result: " << std::to_string(result) << std::endl;
  std::cout << "Calc took: " << fp_ms.count() << " ms" << std::endl;
  std::cout << "____________________________" << std::endl << std::endl;
}


inline std::string Utils::duration_string(std::chrono::duration<long, std::ratio<1, 1000000000>> duration) {
  auto sec = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
  if (sec != 0) {
	return std::to_string(sec) + " sec";
  }
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  if (millis == 0) {
	return std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) + " ns";
  }
  return std::to_string(millis) + " millis";
}

 template<typename Functor>
inline std::chrono::duration<long, std::ratio<1, 1000000000>> Utils::execution_time(Functor functor) {
  auto start = std::chrono::steady_clock::now();
  functor();
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  return diff;
}

*/