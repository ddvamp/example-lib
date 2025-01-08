#include <config.hpp>

#include <iostream>

int main(int argc, char **argv) {
  std::cout << argv[0] << " version " << EXAMPLE_VERSION_MAJOR << '.'
            << EXAMPLE_VERSION_MINOR << '.' << EXAMPLE_VERSION_PATCH
            << std::endl;

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
