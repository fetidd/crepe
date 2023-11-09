#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <format>
// #include "fmt/core.h"
#include <expected>
#include "error.hpp"

namespace crepe_config {
    class CrepeConfig {
        public:
        CrepeConfig() = default;
        CrepeConfig(std::vector<std::string> &args);

        /* get the pattern*/
        std::string getPattern();
        /* get the search file path*/
        std::string getSearchFile();

        private:
        std::string m_search_file;
        std::string m_pattern;
        bool ignore_case;
        void setPattern(std::string ptn);
        Result<void> setSearchFile(std::string path);
        
        /* Parse the vector of args and store them */
        void parse(std::vector<std::string> &args);
    };

     enum class config_error {
        invalid_arguments
    };

    Result<CrepeConfig> create(std::vector<std::string> &args);
}