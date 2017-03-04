#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_IS_STRING_ROTATION, ALL)
{
  assert(!is_string_rotation("watbottle", "bottlawat"));
  assert(is_string_rotation("watbottle", "watbottle"));
  assert(is_string_rotation("watbottle", "atbottlew"));
  assert(is_string_rotation("watbottle", "tbottlewa"));
  assert(is_string_rotation("watbottle", "bottlewat"));
  assert(is_string_rotation("watbottle", "ottlewatb"));
  assert(is_string_rotation("watbottle", "ttlewatbo"));
  assert(is_string_rotation("watbottle", "tlewatbot"));
  assert(is_string_rotation("watbottle", "lewatbott"));
  assert(is_string_rotation("watbottle", "ewatbottl"));
  assert(is_string_rotation("", ""));
}
