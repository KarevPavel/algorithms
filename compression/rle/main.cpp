
#include <iostream>
#include <string>
#include <fstream>
#include "rle.hpp"

static bool str_equals_any(char * suspect, const std::string& f_str, const std::string& s_str) {
  return f_str == suspect || s_str == suspect;
}

static void show_help() {
  std::cout
	  << "\tRLE-algorithm (de)compressor" << std::endl
	  << "\t--help       -h  show information about program" << std::endl
	  << "\t--input      -i  input file" << std::endl
	  << "\t--output     -o  output file or the same as target (w/wo extension) if empty" << std::endl
	  << "\t--decompress -d  decompression" << std::endl
	  << "\t--compress   -c  compression" << std::endl;
}

int main(int arg_count, char ** args) {
  std::string input_file, output_file;
  bool compress = false, decompress = false;

  if (arg_count == 1) {
	show_help();
	return 0;
  }

  for (int i = 0; i < arg_count; i++) {
	if (str_equals_any(args[i], "--help", "-h")) {
	  show_help();
	  return 0;
	}

	if (str_equals_any(args[i], "--output", "-o"))
	  //IOB!!!
	  output_file = args[++i];

	if (str_equals_any(args[i], "--decompress", "-d"))
	  decompress = true;

	if (str_equals_any(args[i], "--compress", "-c"))
	  compress = true;

	if (str_equals_any(args[i], "--input", "-i"))
	  //IOB!!!
	  input_file = args[++i];
  }

  if (compress && decompress) {
	std::cout << "Cannot be signed both params: compress and decompress";
	return 0;
  }

  if (!compress && !decompress) {
	std::cout << "One of args must be specified compress or decompress";
	return 0;
  }

  if (input_file.empty()) {
	std::cout << "Input file cannot be empty!";
	return 0;
  }

  std::ifstream input;
  input.open(input_file);
  if (!input.is_open()) {
	std::cout << "Cannot open file";
	return 0;
  }

  if (compress) {
	if (output_file.empty())
	  output_file = input_file.substr(0, input_file.find_last_of('.'));
	std::ofstream output { output_file + ".rle"};
	RLE::compress_v2(input, output);
  } else {
	if (output_file.empty()) {
	  auto idx = input_file.find_last_of('.');
	  if (idx > 0)
		output_file = input_file.substr(0, --idx);
	  else {
		output_file = input_file + ".decompressed";
	  }
	}
	std::ofstream output{output_file};
	RLE::decompress_V2(input, output);
  }

  return 0;
}