#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "useful.hpp"
#include "crepe_config.hpp"
#include <memory>

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  crepe_config::CrepeConfig cfg;
  std::vector<std::string> lines {};
  try {
    cfg.parse(arguments);
    lines = useful::readFile(cfg.getSearchFile());
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  auto found = useful::searchForPattern(lines, cfg.getPattern());
  std::cout << useful::formatVec(found) << std::endl;
  return 0;
}

void derp() {
  auto x = std::vector<std::string>{"hello"};
}

