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
#include <sstream>
#include <iomanip>

enum POSITION {
  START,
  MID,
  END
};

namespace Utils {

const static char *create_alphabet(char from, char to) {
  char *result = new char[to - from + 1];
  for (char ch = from, i = 0; ch <= to; ch++, i++)
	result[i] = ch;
  return result;
}


template<typename R, typename ...Args>
void print_exec_time_and_result(const std::string &test_name, R (*func)(Args...), Args &&...args);

template<typename T>
void print_array(T array[], size_t lenght, std::ostream &ostream);

template<typename Container>
void print_container_array(Container * array, std::ostream &ostream);

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

template<typename T>
void array_swap(T array[], int a, int b);

template<typename T>
void shift_array(T array[], int, int);

void shift_array(int array[], int a, int b);

template<typename T>
bool check_array_sort(const T array[], size_t lenght);

template<typename T>
T *random_array(T element_count);

template<typename T>
T *asc_array(T element_count);

template<typename SortImpl>
void test_sorting(const std::string &test_name, int element_count, SortImpl *sort);

template<typename FileSort>
std::string test_file_sorting_for_table(const std::string &input_file, int batch_size, FileSort *sort);

template<typename SortImpl>
std::string test_sorting_for_table(int element_count, SortImpl *sort);

template<typename Tree>
std::string test_tree_insert_random_array(int *array, int element_count, Tree *tree);

template<typename Tree>
std::string test_tree_insert_asc_array(int *array, int element_count, Tree *tree);

template<typename Tree>
std::string test_tree_search(int *array, int element_count, Tree *tree);

template<typename Tree>
std::string test_tree_delete(int *array, int element_count, Tree *tree);


template<typename Map>
std::string test_map_insert(int *array, int element_count, Map *map);

template<typename Map>
std::string test_map_search(int *array, int element_count, Map *tree);

template<typename Map>
std::string test_map_delete(int *array, int element_count, Map *tree);

template<typename SortImpl>
void test_sorting_auto(const std::string &test_name, SortImpl *sort);

void print_array(int array[], int start_idx, int end_idx, std::ostream &ostream);

template <typename T>
void print_matrix(T ** matrix, int length);

template <typename T>
void print_2d_array(T ** matrix, int height, int weight);

void generate_file(const std::string &path, char separator, unsigned long N);

template<typename T>
T random_number(T a, T b);

template<typename T>
T find_max(T *array, int length);

template<typename T>
T *array_part(T *array, int start_index, int end_index);

template<typename T>
void overwrite_file(const std::string &file, T *array, int size);

std::pair<std::string, std::string> generate_text_and_pattern(int, const std::string&, POSITION);
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

template<typename T>
inline void Utils::array_swap(T array[], int a, int b) {
  T x = array[a];
  array[a] = array[b];
  array[b] = x;
}

template<typename T>
inline void Utils::shift_array(T array[], int a, int b) {
  for (int i = b; i > a; i--)
	array[i] = array[i - 1];
}

inline void Utils::shift_array(int array[], int a, int b) {
  for (int i = b; i > a; i--)
	array[i] = array[i - 1];
}

inline void Utils::print_array(int array[], int start_idx, int end_idx, std::ostream &ostream) {
  ostream << "Array [ ";
  for (int i = start_idx; i <= end_idx; ++i)
	ostream << array[i] << ", ";
  ostream << "]" << std::endl;
}

template <typename T>
inline void Utils::print_matrix(T ** matrix, int length) {
  std::cout << "Matrix:\n";
  	for (int i = 0; i < length; i++) {
  	  std::cout << "| ";
	  for (int j = 0; j < length; j++) {
		std::cout << std::setw(2) << matrix[i][j] << "  ";
	  }
	  std::cout << "|\n";
	}
}

template <typename T>
inline void Utils::print_2d_array(T ** matrix, int columns, int rows) {
  std::cout << "2D Array:\n";
  for (int i = 0; i < rows; i++) {
	std::cout << "| ";
	for (int j = 0; j < columns; j++) {
	  std::cout << std::setw(2) << matrix[j][i] << "  ";
	}
	std::cout << "|\n";
  }
}

template<typename T>
inline void Utils::print_array(T array[], size_t length, std::ostream &ostream) {
  ostream << "Array [ ";
  for (int i = 0; i < length; ++i)
	ostream << array[i] << ", ";
  ostream << "]" << std::endl;
}

template<typename Container>
inline void Utils::print_container_array(Container * array, std::ostream &ostream) {
  ostream << "Array [ ";
  for (int i = 0; i < array->size(); i++)
    ostream << array->get(i) << ", ";
  ostream << "]" << std::endl;
}

template<typename T>
inline bool Utils::check_array_sort(const T array[], size_t lenght) {
  for (int i = 1; i < lenght || (&array[i]) == nullptr; ++i)
	if (array[i] < array[i - 1]) {
	  std::cout << "At indices [" << (i - 1) << "] and [" << i << "] values " << array[i - 1] << " > " << array[i]
				<< " is true" << std::endl;
	  return false;
	}
  return true;
}

/*long *Utils::random_array(int element_count) {
  auto array = new long[element_count];
  for (int i = 0; i < element_count; i++)
	array[i] = random_number<long>(0, element_count);
  return array;
}*/

template<typename T>
T *Utils::random_array(T element_count) {
  auto array = new T[element_count];
  for (int i = 0; i < element_count; i++)
	array[i] = random_number<T>(0, std::numeric_limits<int>::max());
  return array;
}

template<typename T>
T *Utils::asc_array(T element_count) {
  int *array = new T[element_count];
  for (int i = 0; i < element_count; i++)
	array[i] = i;
  return array;
}

/*int * generate_asc_array() {
  int *array = new int[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
	array[i] = i;
}*/

template<typename SortImpl>
inline void Utils::test_sorting(const std::string &test_name, int element_count, SortImpl *sort) {
  std::cout << "--------" << test_name << "----------" << std::endl;
  auto arr = random_array(element_count);
  auto start = std::chrono::steady_clock::now();
  sort->sort(arr, element_count);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  std::cout << "| For sorting " << element_count << " elements took: " << fp_ms.count() << " ms" << std::endl;
  std::cout << "| Check elements order: " << (Utils::check_array_sort(arr, element_count) ? "OK" : "ERROR")
			<< std::endl;
  std::cout << "-----------------------------------" << std::endl << std::endl;
}

template<typename SortImpl>
inline std::string Utils::test_sorting_for_table(int element_count, SortImpl *sort) {
  auto arr = random_array<long>(element_count);
  auto start = std::chrono::steady_clock::now();
  sort->sort(arr, element_count);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  bool isOk = Utils::check_array_sort(arr, element_count);
  return isOk ? std::to_string(fp_ms.count()) : "ERROR";
}

template<typename Tree>
std::string Utils::test_tree_insert_asc_array(int *array, int element_count, Tree *tree) {
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < element_count; i++)
	tree->insert(array[i]);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Tree>
std::string Utils::test_tree_insert_random_array(int *array, int element_count, Tree *tree) {
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < element_count; i++)
	tree->insert(array[i]);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Tree>
std::string Utils::test_tree_search(int *array, int element_count, Tree *tree) {
  auto start = std::chrono::steady_clock::now();
  for (int i = element_count; i > 0; i /= 10)
	tree->search(array[i]);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Tree>
std::string Utils::test_tree_delete(int *array, int element_count, Tree *tree) {
  auto start = std::chrono::steady_clock::now();
  for (int i = element_count; i > 0; i /= 10)
	tree->remove(array[i]);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Map>
std::string Utils::test_map_insert(int *array, int element_count, Map *map) {
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < element_count; i++)
	map->put(std::to_string((char)array[i]), array[i]);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Map>
std::string Utils::test_map_search(int *array, int element_count, Map *tree) {
  auto start = std::chrono::steady_clock::now();
  for (int i = element_count; i > 0; i /= 10)
	tree->contains(std::to_string((char)array[i]));
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename Map>
std::string Utils::test_map_delete(int *array, int element_count, Map *map) {
  auto start = std::chrono::steady_clock::now();
  for (int i = element_count; i > 0; i /= 10)
	map->remove(std::to_string((char)array[i]));
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  return std::to_string(fp_ms.count());
}

template<typename SortImpl>
inline void Utils::test_sorting_auto(const std::string &test_name, SortImpl *sort) {
  std::cout << "--------" << test_name << "----------" << std::endl;
  for (int pow = 2; pow < 7; pow++) {
	int element_count = std::pow(10, pow);
	auto arr = random_array<int>(element_count);
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

inline void Utils::generate_file(const std::string &path, char separator, unsigned long N) {
  std::ofstream ofstream;
  ofstream.open(path);
  for (int i = 0; i < N; i++) {
	if (i == 0)
	  ofstream << random_number<unsigned short>(0, 65535);
	else
	  ofstream << separator << random_number<unsigned short>(0, 65535);
  }
}

template<typename T>
inline T Utils::random_number(T a, T b) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<T> dist(a, b);
  return dist(mt);
}

template<typename T>
inline T Utils::find_max(T *array, int length) {
  int max = 0;
  for (int l = 0, r = length; l < r; l++, r--) {
	if (max < array[l])
	  max = array[l];
	if (max < array[r])
	  max = array[r];
  }
  return max;
}

template<typename T>
T *Utils::array_part(T *array, int start_index, int end_index) {
  T *new_array = new T[end_index - start_index + 1];
  for (int i = start_index, j = 0; i <= end_index; i++, j++)
	new_array[j] = array[i];
  return new_array;
}

template<typename T>
void Utils::overwrite_file(const std::string &file, T *array, int size) {
  std::ofstream ofstream;
  //remove(file.c_str());
  ofstream.open(file);
  if (!ofstream)
	throw std::runtime_error("Cannot open file! " + file);
  for (int i = 0; i < size; i++)
	if (i == 0)
	  ofstream << array[i];
	else
	  ofstream << '\n' << array[i];
}

template<typename FileSort>
inline std::string Utils::test_file_sorting_for_table(const std::string &input_file, int batch_size, FileSort *sort) {
  auto start = std::chrono::high_resolution_clock::now();
  sort->file_sort(input_file, batch_size);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = end - start;
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  auto in_sec = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "duration: " << duration.count() << " microseconds" << std::endl;
  std::cout << "in_sec " << in_sec.count() << " seconds" << std::endl;
  return std::to_string(fp_ms.count());
}

inline std::pair<std::string, std::string> Utils::generate_text_and_pattern(int text_length = 1024,
																			const std::string& pattern = "@@@@@@",
																			POSITION position = POSITION::MID) {
  std::stringstream ss_text;
  std::stringstream ss_pattern;
  for (int i = 0; i < text_length; i++)
    ss_text << 'a';

  std::string text = ss_text.str();
  int pattern_length = pattern.length();

  int insert_pattern_pos = 0;
  if (position == POSITION::MID)
	insert_pattern_pos = text_length / 2;
  else if (position == POSITION::END)
    insert_pattern_pos = text_length - pattern_length;

  for (int i = 0; i < pattern_length; i++)
    text[insert_pattern_pos + i] = pattern[i];

  return std::make_pair(pattern, text);
}