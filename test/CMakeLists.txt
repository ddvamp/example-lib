cmake_minimum_required(VERSION 3.31)

project(
  example-lib-tests
  LANGUAGES CXX
)

if (PROJECT_IS_TOP_LEVEL)
  message(FATAL_ERROR "$The example-lib-tests project must not be top-level")
endif()

add_executable(example-lib-tests)
target_sources(example-lib-tests PRIVATE main.cpp)

set_target_properties(
  example-lib-tests PROPERTIES

  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF

  DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)
