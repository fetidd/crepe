#include "gtest/gtest.h"
#include "src/crepe_config.hpp"
#include "tests/useful_test_code.hpp"
#include <stdexcept>

using namespace std;
using namespace crepe_config;

TEST(crepeConfigUnitTests, getPattern) {
    vector<string> args {"crepe", "pattern", "filepath"};
    CrepeConfig cfg(args);
    EXPECT_EQ(cfg.getPattern(), "pattern");
}

TEST(crepeConfigUnitTests, getSearchFile) {
    vector<string> args {"crepe", "pattern", "filepath"};
    CrepeConfig cfg(args);
    EXPECT_EQ(cfg.getSearchFile(), "filepath");
}

// TEST(crepeConfigUnitTests, constructorValidation) {
//     EXPECT_THROW({
//         vector<string> args {"arg1", "arg2"};
//         try {
//             CrepeConfig cfg(args);
//         } catch (const exception &e) {
//             EXPECT_STREQ("Need at least two arguments (pattern then file to search in)", e.what());
//             throw;
//         }
//     }, invalid_argument);
// }
