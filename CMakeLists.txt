cmake_minimum_required(VERSION 3.10)

project(github_ci_cd CXX)

add_executable(${PROJECT_NAME} main.cpp)

enable_testing()
add_executable(simple_test test.cpp)
add_test(NAME simple_test COMMAND simple_test)