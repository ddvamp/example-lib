cmake_minimum_required(VERSION 3.20)

project(
  example # sets PROJECT_NAME
  VERSION 0.0.4
  DESCRIPTION "project to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example"
  LANGUAGES CXX
)

set(proj_name ${PROJECT_NAME})
set(proj_dir ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_COMPILER "/usr/bin/clang++") # avoid this
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${proj_name})

configure_file(${proj_dir}/config.hpp.in config.hpp @ONLY)

target_include_directories(
  ${proj_name}
  PUBLIC ${PROJECT_BINARY_DIR}
  PUBLIC ${proj_dir}
)

target_sources(${proj_name} PUBLIC ${proj_dir}/main.cpp)
