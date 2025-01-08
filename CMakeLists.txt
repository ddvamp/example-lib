cmake_minimum_required(VERSION 3.12)

project(
  example # sets PROJECT_NAME
  VERSION 0.0.2
  DESCRIPTION "project to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example"
  LANGUAGES CXX
)

add_executable(${PROJECT_NAME} main.cpp)
