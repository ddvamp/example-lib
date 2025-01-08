cmake_minimum_required(VERSION 3.20)

project(
  example # sets PROJECT_NAME
  VERSION 0.0.3
  DESCRIPTION "project to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example"
  LANGUAGES CXX
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++") # avoid this
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp)

configure_file(config.hpp.in config.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
