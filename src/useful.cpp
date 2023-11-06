#include "src/useful.h"

using namespace std;

vector<string> splitStr(string input, char split_char) {
  if (input.length() == 1 && input[0] == split_char) return {}; // if the string is just the split_char then the vector will be empty
  size_t pos {0}, split_index {0};
  vector<string> split_vec {};
  while (pos < input.length()) {
    split_index = input.find(split_char, pos);    
    if (split_index == string::npos) {
      split_vec.push_back(input.substr(pos));
      break;
    }
    string to_add = input.substr(pos, split_index - pos);
    if (to_add.length() > 0) {
      split_vec.push_back(to_add);
    }
    pos = split_index + 1; // jump over the split_char
  }
  return split_vec;
}

string formatVec(vector<string>* vec, string join_str) {
  string output {""};
  for (size_t i = 0; i < vec->size(); i++) {
    if (i != 0) {
      output += join_str;
    }
    output += "'";
    output += vec->at(i);
    output += "'";
  }
  return output;
}
