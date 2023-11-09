#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
// #include <format>
#include "fmt/core.h"

namespace crepe_config {
    class CrepeConfig {
        public:
        /* Construct a CrepeConfig from the arguments passed to main*/
        CrepeConfig() = default;
        CrepeConfig(std::vector<std::string> args);

        /* Parse the vector of args and store them */
        void parse(std::vector<std::string> args);

        /* get the pattern*/
        std::string getPattern();
        /* get the search file path*/
        std::string getSearchFile();

        private:
        std::string m_search_file;
        std::string m_pattern;
        bool ignore_case;
        void setPattern(std::string ptn);
        void setSearchFile(std::string path);
    };
}