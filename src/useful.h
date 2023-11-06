#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <format>
#include <regex>

std::vector<std::string> splitStr(std::string input, char split_char='\n');
std::string formatVec(std::vector<std::string> &vec, std::string join_str=", ");
std::vector<std::string> readFile(std::string file_path);
std::vector<std::string> searchForPattern(std::vector<std::string> &lines, std::string pattern);
