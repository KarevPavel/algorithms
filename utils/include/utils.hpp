//
// Created by yacopsae on 13/02/22.
//

#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <cmath>
#include <future>
#include <fstream>
#include <random>

namespace Utils {

template<typename R, typename ...Args>
void print_exec_time_and_result(const std::string &test_name, R (*func)(Args...), Args &&...args);

void print_array(int array[], size_t lenght, std::ostream& ostream);

template<typename T>
std::string to_string(T t1);

template<typename T>
std::string to_string(T t1, T t2);

template<typename T, typename V>
std::string to_string(T t, V v);

template<typename Container>
void multiple_inserts_exec_time(const std::string &test_name, Container container);

template<typename Container>
void loop(Container container, long loop_count);

template<typename TF, typename TDuration, class... TArgs>
void run_with_timeout(TF &f, TDuration timeout, TArgs &&... args);

void array_swap(int array[], int a, int b);

void shift_array(int array[], int a, int b);

bool check_array_sort(const int array[], size_t lenght);

int * random_array(int element_count);

template<typename SortImpl>
void test_sorting(const std::string& test_name, int element_count, SortImpl * sort);

template<typename SortImpl>
std::string table_sorting(int element_count, SortImpl * sort);

template<typename SortImpl>
void test_sorting_auto(const std::string& test_name, SortImpl * sort);

void print_array(int array[], int start_idx, int end_idx, std::ostream& ostream);

void generate_file(const std::string & path, unsigned long N);

int random_int(int a, int b);
}

template<typename T>
inline std::string Utils::to_string(T t1) {
  return std::to_string(t1);
}

template<typename T>
inline std::string Utils::to_string(T t1, T t2) {
  return std::to_string(t1) + " " + std::to_string(t2);
}

template<typename T, typename V>
inline std::string Utils::to_string(T t, V v) {
  return std::to_string(t) + " " + std::to_string(v);
}

template<typename R, typename ...Args>
inline void Utils::print_exec_time_and_result(const std::string &test_name, R (*func)(Args...), Args &&...args) {
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

template<typename Container>
inline void Utils::multiple_inserts_exec_time(const std::string &test_name, Container container) {
  using namespace std::chrono_literals;
  std::cout << "-------- " << test_name << " ----------" << std::endl;
  long loop_count = 10;
  bool timeout_error = false;
  const auto duration = 10s;
  while (!timeout_error) {
	loop_count *= 10;
	auto start = std::chrono::steady_clock::now();
	try {
	  Utils::run_with_timeout<void(Container, long)>(Utils::loop, duration, std::move(container), loop_count);
	  timeout_error = false;
	} catch (std::runtime_error &error) {
	  timeout_error = true;
	}
	if (!timeout_error) {
	  auto end = std::chrono::steady_clock::now();
	  std::chrono::duration<double, std::milli> fp_ms = end - start;
	  std::cout << "For " << loop_count << " elements took: " << fp_ms.count() << " ms" << std::endl;
	} else {
	  std::cout << "For " << loop_count << " elements took: inf. ms" << std::endl;
	}
  }
  std::cout << "-----------------------------------" << std::endl << std::endl;
}

template<typename Container>
inline void Utils::loop(Container container, long loop_count) {
  for (long i = 0; i <= loop_count; i++)
	container.put(i);
  container.clean();
}

template<typename TF, typename TDuration, class... TArgs>
inline void Utils::run_with_timeout(TF &f, TDuration timeout, TArgs &&... args) {
  std::packaged_task<TF> task(f);
  auto future = task.get_future();
  std::thread thr(std::move(task), std::forward<TArgs>(args)...);
  if (future.wait_for(timeout) != std::future_status::timeout) {
	thr.join();
  } else {
	thr.detach();
	throw std::runtime_error("Timeout");
  }
}

inline void Utils::array_swap(int array[], int a, int b) {
  int x = array[a];
  array[a] = array[b];
  array[b] = x;
}

inline void Utils::shift_array(int array[], int a, int b) {
	for (int i = b; i > a; i--) {
	  array[i] = array[i - 1];
	}
}

inline void Utils::print_array(int array[], int start_idx, int end_idx, std::ostream& ostream) {
  ostream << "Array [ ";
  for (int i = start_idx; i <= end_idx; ++i)
	ostream << array[i] << ", ";
  ostream << "]" << std::endl;
}

inline void Utils::print_array(int array[], size_t lenght, std::ostream& ostream) {
  ostream << "Array [ ";
  for (int i = 0; i < lenght; ++i)
	ostream << array[i] << ", ";
  ostream << "]" << std::endl;
}

inline bool Utils::check_array_sort(const int array[], size_t lenght) {
  for (int i = 1; i < lenght; ++i)
    if (array[i] < array[i - 1])
	  return false;
  return true;
}

int * Utils::random_array(int element_count) {
  auto array = new int[element_count];
  for (int i = 0; i < element_count; i++)
	array[i] = random_int(0, element_count);
  return array;
}

template<typename SortImpl>
inline void Utils::test_sorting(const std::string& test_name, int element_count, SortImpl * sort) {
  std::cout << "--------" << test_name << "----------" << std::endl;
  auto arr = random_array(element_count);
  auto start = std::chrono::steady_clock::now();
  sort->sort(arr, element_count);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  std::cout << "| For sorting " << element_count << " elements took: " << fp_ms.count() << " ms" << std::endl;
  std::cout << "| Check elements order: " << (Utils::check_array_sort(arr, element_count) ? "OK" : "ERROR") << std::endl;
  std::cout << "-----------------------------------" << std::endl << std::endl;
}

template<typename SortImpl>
inline std::string Utils::table_sorting(int element_count, SortImpl * sort) {
  auto arr = random_array(element_count);
  auto start = std::chrono::steady_clock::now();
  sort->sort(arr, element_count);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return Utils::check_array_sort(arr, element_count) ? std::to_string(fp_ms.count()) : "ERROR";
}

template<typename SortImpl>
inline void Utils::test_sorting_auto(const std::string& test_name, SortImpl * sort) {
  std::cout << "--------" << test_name << "----------" << std::endl;
  for (int pow = 2; pow < 7; pow++) {
	int element_count = std::pow(10, pow);
	auto arr = random_array(element_count);
	auto start = std::chrono::steady_clock::now();
	sort->sort(arr, element_count);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = end - start;
	if (pow == 2)
	  std::cout << "| Check elements order: " << (Utils::check_array_sort(arr, element_count) ? "OK" : "ERROR")
				<< std::endl;

	std::cout << "| For sorting " << element_count << " elements took: " << fp_ms.count() << " ms" << std::endl;
  }
  std::cout << "-----------------------------------" << std::endl << std::endl;
}

inline void Utils::generate_file(const std::string & path, unsigned long N) {
  std::ofstream ofstream;
  ofstream.open(path);
  for (int i = 0; i < N; i++) {
	ofstream << random_int(0, 65535);
	if (N - 1 != i)
	  ofstream << std::endl;
  }
}

inline int Utils::random_int(int a, int b) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(a, b);
  return dist(mt);
}