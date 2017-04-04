#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_IS_ONE_WAY, ALL)
{
  assert(is_one_way("pale", "ple"));
  assert(is_one_way("", ""));
  assert(is_one_way("pales", "pale"));
  assert(is_one_way("pale", "bale"));
  assert(!is_one_way("pale", "bake"));
  assert(is_one_way("pale", "pale"));
}

