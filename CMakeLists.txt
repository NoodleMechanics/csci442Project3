cmake_minimum_required(VERSION 3.13)
project(Project-3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project-3 src/main.cpp src/flag_parser/flag_parser.cpp src/flag_parser/flag_parser_tests.cpp)