cmake_minimum_required(VERSION 3.20)

project(
  liba
  VERSION 0.0.1
  DESCRIPTION "Some library to study CMake"
  HOMEPAGE_URL "https://github.com/ddvamp/example"
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
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

if (sources)
  message(STATUS "Object library: ${name}")
  add_library(${name} OBJECT)
  target_include_directories(${name} PUBLIC ${dir}/src)
  target_sources(${name} PRIVATE ${sources})
else()
  message(STATUS "Interface library: ${name}")
  add_library(${name} INTERFACE)
  target_include_directories(${name} INTERFACE ${dir}/src)
endif()

add_library(${name}::${name} ALIAS ${name})

set_target_properties(
  ${name} PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
  SOVERSION ${PROJECT_VERSION_MAJOR}
  VERSION ${PROJECT_VERSION}
)

# if(LIBA_BUILD_TESTS)
#   enable_testing()
#   add_subdirectory(test)
# endif()
#
# if(LIBA_BUILD_EXAMPLES)
#   add_subdirectory(example)
# endif()
