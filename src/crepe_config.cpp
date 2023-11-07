#include "crepe_config.hpp"

crepe_config::CrepeConfig::CrepeConfig(std::vector<std::string> args)  {
    this->parse(args);
}

void crepe_config::CrepeConfig::parse(std::vector<std::string> args) {
    if (args.size() < 3) throw std::invalid_argument("Need at least two arguments (pattern then file to search in)");
    this->setPattern(args[1]);
    this->setSearchFile(args[2]);
}

void crepe_config::CrepeConfig::setPattern(std::string ptn) {
    this->pattern = ptn;
}

void crepe_config::CrepeConfig::setSearchFile(std::string path) {
    if (path.size() == 0) throw std::invalid_argument(std::format("bad filepath {}", path));
    this->search_file = path;
}

std::string crepe_config::CrepeConfig::getPattern() {
    return this->pattern;
}

std::string crepe_config::CrepeConfig::getSearchFile() {
    return this->search_file;
}