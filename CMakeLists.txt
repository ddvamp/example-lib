cmake_minimum_required(VERSION 3.31)

project(
  liba
  VERSION 0.1.0
  DESCRIPTION "Some library to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example-lib"
  LANGUAGES CXX
)

# include(cmake/utils.cmake)
# include(GNUInstallDirs)
#
# option(LIBA_BUILD_TESTS "Build liba tests" OFF)
# option(LIBA_BUILD_EXAMPLES "Build liba examples" OFF)

set(name ${PROJECT_NAME})
set(dir ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE sources ${dir}/src/*.cpp)

if (sources)
  set(type object)
  add_library(${name} OBJECT)
  target_sources(${name} PRIVATE ${sources})
else()
  set(type interface)
  add_library(${name} INTERFACE)
endif()
message(STATUS "The ${name} library is of ${type} type")

set(headers ${dir}/..)
cmake_path(NORMAL_PATH headers)
target_include_directories(${name} INTERFACE ${headers} PRIVATE ${dir}/src)

add_library(${name}::${name} ALIAS ${name})

set_target_properties(
  ${name} PROPERTIES

  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF

  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

# if(LIBA_BUILD_TESTS)
#   enable_testing()
#   add_subdirectory(test)
# endif()
#
# if(LIBA_BUILD_EXAMPLES)
#   add_subdirectory(example)
# endif()
