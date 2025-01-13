cmake_minimum_required(VERSION 3.31)

project(
  liba
  VERSION 0.1.0
  DESCRIPTION "Some library to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example-lib"
  LANGUAGES CXX
)

set(name ${PROJECT_NAME})
set(dir ${PROJECT_SOURCE_DIR})

if (PROJECT_IS_TOP_LEVEL)
  message(FATAL_ERROR "$The {name} project must not be top-level")
endif()

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

# ------------------------------------------------------------------------------
# tests and examples
# ------------------------------------------------------------------------------

string(TOUPPER ${name}_BUILD_TESTS tests)
option(${tests} "Build tests for ${name}" OFF)
if(${tests})
  enable_testing()
  add_subdirectory(test)
endif()

string(TOUPPER ${name}_BUILD_EXAMPLES examples)
option(${examples} "Build examples for ${name}" OFF)
if(${examples})
  add_subdirectory(example)
endif()
