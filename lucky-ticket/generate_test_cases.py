#!/usr/bin/env python3
import argparse
import os
import sys
import re


class TestEntry:
    name: str
    digitCount: int
    answer: str

    def __init__(self, name, digitCount, answer):
        self.name = name
        self.digitCount = digitCount
        self.answer = answer

    def get_answer(self):
        return self.answer

    def set_answer(self, value):
        self.answer = value

    def get_digitCount(self):
        return self.digitCount

    def set_digitCount(self, value):
        self.digitCount = value

    def get_name(self):
        return self.name

    def set_name(self, value):
        self.name = value


def generate_header(path, outputdir):
    dictionary = dict()
    for _, _, files in os.walk(path):
        for file in files:
            match = re.match('test\.(\d+)\.(out|in)', file)
            number = match.group(1)
            in_or_out = match.group(2)
            test_name = 'test_' + number
            with open(path + '/' + file, 'r') as fp:
                data = fp.read()
            file_content = data.split()
            if dictionary.__contains__(test_name):
                if in_or_out == 'in':
                    dictionary[test_name].set_digitCount(file_content)
                if in_or_out == 'out':
                    dictionary[test_name].set_answer(file_content)
            else:
                if in_or_out == 'in':
                    dictionary[test_name] = TestEntry(test_name, file_content, 0)
                if in_or_out == 'out':
                    dictionary[test_name] = TestEntry(test_name, 0, file_content)

    class_definition = """
    #pragma once
    #include <string>
    class TestEntry {
         public:
          TestEntry(std::string name, int degit_count, long long result);
          const std::string &GetName() const;
          int GetDegitCount() const;
          long long GetResult() const;
        
         private:
          std::string name;
          int degit_count;
          long long result;
    };"""
    for key in dictionary:
        value = dictionary[key]
        value.__class__ = TestEntry
        class_definition += '\nstatic const TestEntry ' \
                            + key.upper() \
                            + '= TestEntry{"' \
                            + key + '", ' \
                            + str(value.get_digitCount()[0]) \
                            + ', ' + value.get_answer()[0] + '};'

    with open(outputdir + '/test_cases.hpp', 'w') as f:
        f.write(class_definition)


def generate_implementation(outputdir):
    class_implementation = """
    #include "test_entry.hpp"
    #include <utility>
    TestEntry::TestEntry(std::string name, int degit_count, long long result)
    : name(std::move(name)), degit_count(degit_count), result(result) {}
    const std::string &TestEntry::GetName() const { return name; }
    int TestEntry::GetDegitCount() const { return degit_count; }
    long long TestEntry::GetResult() const { return result; }
    """
    with open(outputdir + '/test_cases.cpp', 'w') as f:
        f.write(class_implementation)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate some cpp/hpp files.')
    parser.add_argument('inputfile')
    parser.add_argument('outputDir')
    parser.add_argument('--print-dependencies',
                        dest='print_dependencies',
                        action='store_const',
                        default=False,
                        const=True,
                        help='Print file dependencies, do not generate anything')

    args = parser.parse_args()
    if args.print_dependencies:
        print('test_cases.hpp;test_cases.cpp')
        sys.exit(0)
    else:
        generate_header(args.inputfile, args.outputDir)
        generate_implementation(args.outputDir)
        print('GENERATED!')
        sys.exit(0)
