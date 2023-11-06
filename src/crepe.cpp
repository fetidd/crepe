#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include "useful.h"
#include <stdexcept>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Need two arguments (pattern then file to search in)" << std::endl;
    return 1;
  }
  std::vector<std::string> lines {};
  try {
    lines = readFile(argv[2]);
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  auto found = searchForPattern(lines, argv[1]);
  std::cout << formatVec(found) << std::endl;
  return 0;
}

