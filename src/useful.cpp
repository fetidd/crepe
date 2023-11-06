#include "src/useful.h"

std::vector<std::string> splitStr(std::string input, char split_char) {
  if (input.length() == 1 && input[0] == split_char) return {}; // if the string is just the split_char then the vector will be empty
  size_t pos {0}, split_index {0};
  std::vector<std::string> split_vec {};
  while (pos < input.length()) {
    split_index = input.find(split_char, pos);    
    if (split_index == std::string::npos) {
      split_vec.push_back(input.substr(pos));
      break;
    }
    std::string to_add = input.substr(pos, split_index - pos);
    if (to_add.length() > 0) {
      split_vec.push_back(to_add);
    }
    pos = split_index + 1; // jump over the split_char
  }
  return split_vec;
}

std::string formatVec(std::vector<std::string> &vec, std::string join_str) {
  std::string output {""};
  for (size_t i = 0; i < vec.size(); i++) {
    if (i != 0) {
      output += join_str;
    }
    output += "'";
    output += vec.at(i);
    output += "'";
  }
  return output;
}

std::vector<std::string> readFile(std::string file_path) {
  std::ifstream file(file_path);
  if (!file) {
    std::string error_msg = std::format("File {0} does not exist", file_path);
    throw std::invalid_argument(error_msg);
  }
  std::vector<std::string> lines;
  std::string buf;
  while (std::getline(file, buf)) {
    lines.push_back(buf);
  }
  return lines;
}

std::vector<std::string> searchForPattern(std::vector<std::string> &lines, std::string pattern_str) {
  std::regex pattern(pattern_str);
  std::vector<std::string> found {};
  for (auto line : lines) {
    if (std::regex_search(line, pattern)) {
      found.push_back(line);
    }
  }
  return found;
}