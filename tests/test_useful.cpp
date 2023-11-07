#include <stdexcept>
#include "src/useful.hpp"
#include "gtest/gtest.h"
#include "tests/useful_test_code.hpp"

using namespace std;

TEST(usefulUnitTests, splitStrCases) {  
  TestList<string, vector<string>> tests {
    {"", {}},
    {"\n", {}},
    {"one\ntwo", {"one", "two"}},
    {"one\ntwo\n", {"one", "two"}},
    {"one\ntwo\nthree", {"one", "two", "three"}},
    {"one\ntwo\nthree\n", {"one", "two", "three"}},
    {"\none\ntwo\nthree\n", {"one", "two", "three"}},
  };
  for (auto [input, exp] : tests) {
    EXPECT_EQ(exp, useful::splitStr(input));
  }
}

TEST(usefulUnitTests, formatVecCases) {
  TestList<vector<string>, string, string> tests {
    {{}, "", ""},
    {{"one"}, ", ", "'one'"},
    {{"one", "two"}, ", ", "'one', 'two'"},    
  };
  for (auto [input, join_str, exp] : tests) {
    EXPECT_EQ(exp, useful::formatVec(input, join_str));
  }
}

TEST(usefulUnitTests, readFileCases) {
  TestList<string, vector<string>> tests {
    {"../tests/test_file.txt", {"line 1", "line 2", "line 3"}},
  };
  for (auto [input, exp] : tests) {
    EXPECT_EQ(exp, useful::readFile(input));
  }
}

TEST(usefulUnitTests, readFileFileNotFound) {
  EXPECT_THROW({
    try {
      useful::readFile("nope.txt");
    } catch (const std::exception &e) {
      EXPECT_STREQ("File nope.txt does not exist", e.what());
      throw;
    }
  }, std::invalid_argument);
}

TEST(usefulUnitTests, searchForPatternCases) {
  TestList<vector<string>, string, vector<string>> tests {
    {std::vector<std::string>{}, std::string{""}, std::vector<std::string>{}},
    {{"hello my name is Ben"}, "", {"hello my name is Ben"}},
    {{"hello my name is Ben"}, "!!?!#", {}},
    {{"hello my name is Ben"}, "Ben", {"hello my name is Ben"}},
    {{"hello my name is Ben"}, "NotBen", {}},
    {{"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}, "hello my.* name is .+", {"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}},
    {{"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}, "hello my.* name is .*e.*", {"hello my name is Ben", "hello my brother's name is George"}},
  };
  for (auto [lines, pattern, exp] : tests) {
    EXPECT_EQ(exp, useful::searchForPattern(lines, pattern));
  }
}
