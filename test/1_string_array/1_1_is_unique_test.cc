#include <string_array/string_array.h>
#include "gtest/gtest.h"

TEST(STRING_IS_UNIQUE, TEST_ALL)
{
  EXPECT_TRUE(is_unique(""));
  EXPECT_TRUE(is_unique("a"));
  EXPECT_FALSE(is_unique("aa"));
  EXPECT_TRUE(is_unique("abcdefgABCHIJZ"));
  EXPECT_FALSE(is_unique("abcdefgABCHIJZa"));
}
