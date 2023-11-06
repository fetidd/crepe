#include "src/useful.h"
#include "gtest/gtest.h"

using namespace std;

TEST(useful, splitStr) {  
  vector<tuple<string, vector<string>>> tests {
    {"", {}},
    {"\n", {}},
    {"one\ntwo", {"one", "two"}},
    {"one\ntwo\n", {"one", "two"}},
    {"one\ntwo\nthree", {"one", "two", "three"}},
    {"one\ntwo\nthree\n", {"one", "two", "three"}},
    {"\none\ntwo\nthree\n", {"one", "two", "three"}},
  };
  for (auto [input, exp] : tests) {
    EXPECT_EQ(exp, splitStr(input));
  }
}

TEST(useful, formatVec_string) {
  vector<tuple<vector<string>, string, string>> tests {
    {{}, "", ""},
    {{"one"}, ", ", "'one'"},
    {{"one", "two"}, ", ", "'one', 'two'"},    
  };
  for (auto [input, join_str, exp] : tests) {
    EXPECT_EQ(exp, formatVec(&input, join_str));
  }
}
