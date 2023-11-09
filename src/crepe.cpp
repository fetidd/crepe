#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "useful.hpp"
#include "crepe_config.hpp"
#include <memory>
#include <expected>
#include "error.hpp"

using namespace crepe_config;
using namespace useful;

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  Result<CrepeConfig> config_result = create(arguments);
  if (config_result) { // program is configured correctly
    CrepeConfig cfg = config_result.value();
    Result<std::vector<std::string>> lines_res = readFile(cfg.getSearchFile());
    if (!lines_res) exit(1);
    auto lines = lines_res.value();
    auto found = searchForPattern(lines, cfg.getPattern());
    std::cout << formatVec(found) << std::endl;
    return 0;
  } else {
    std::cout << config_result.error().message << std::endl;
    return 1;
  }
}
