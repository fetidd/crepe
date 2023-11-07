#include "gtest/gtest.h"
#include "src/crepe_config.hpp"
#include "tests/useful_test_code.hpp"
#include <stdexcept>

using namespace std;
using namespace crepe_config;

TEST(crepeConfigUnitTests, constructorValidation) {
    EXPECT_THROW({
        try {
            CrepeConfig cfg({"arg1", "arg2"});
        } catch (const exception &e) {
            EXPECT_STREQ("Need at least two arguments (pattern then file to search in)", e.what());
            throw;
        }
    }, invalid_argument);
}

TEST(crepeConfigUnitTests, getPattern) {
    CrepeConfig cfg({"crepe", "pattern", "filepath"});
    EXPECT_EQ(cfg.getPattern(), "pattern");
}

TEST(crepeConfigUnitTests, getSearchFile) {
    CrepeConfig cfg({"crepe", "pattern", "filepath"});
    EXPECT_EQ(cfg.getSearchFile(), "filepath");
}
