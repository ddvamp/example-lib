cmake_minimum_required(VERSION 3.9)

project(
  example # sets PROJECT_NAME
  VERSION 0.0.1
  DESCRIPTION "project to study CMake"
  LANGUAGES CXX
)

add_executable(${PROJECT_NAME} main.cpp)
