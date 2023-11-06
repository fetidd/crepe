#include "src/useful.h"
#include "gtest/gtest.h"
#include <stdexcept>
#include <format>
#include <typeinfo>

using namespace std;

TEST(useful, splitStrCases) {  
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

TEST(useful, formatVecCases) {
  vector<tuple<vector<string>, string, string>> tests {
    {{}, "", ""},
    {{"one"}, ", ", "'one'"},
    {{"one", "two"}, ", ", "'one', 'two'"},    
  };
  for (auto [input, join_str, exp] : tests) {
    EXPECT_EQ(exp, formatVec(input, join_str));
  }
}

TEST(useful, readFileCases) {
  vector<tuple<string, vector<string>>> tests {
    {"../tests/test_file.txt", {"line 1", "line 2", "line 3"}},
  };
  for (auto [input, exp] : tests) {
    EXPECT_EQ(exp, readFile(input));
  }
}

TEST(useful, readFileFileNotFound) {
  EXPECT_THROW({
    try {
      readFile("nope.txt");
    } catch (const std::exception &e) {
      EXPECT_STREQ("File nope.txt does not exist", e.what());
      throw;
    }
  }, std::invalid_argument);
}

TEST(useful, searchForPatternCases) {
  vector<tuple<vector<string>, string, vector<string>>> tests {
    {{}, "", {}},
    {{"hello my name is Ben"}, "", {"hello my name is Ben"}},
    {{"hello my name is Ben"}, "Ben", {"hello my name is Ben"}},
    {{"hello my name is Ben"}, "NotBen", {}},
    {{"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}, "hello my.* name is .+", {"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}},
  };
  for (auto [lines, pattern, exp] : tests) {
    EXPECT_EQ(exp, searchForPattern(lines, pattern));
  }
}
