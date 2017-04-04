#include <gtest/gtest.h>
#include <string_array/string_array.h>

TEST(TEST_IS_PERMULATION, ALL)
{
  assert(is_permulation("", "a") == false);
  assert(is_permulation("a", "a") == true);
  assert(is_permulation("abcdefg", "bdcaefg") == true);
  assert(is_permulation("abccdefg", "bdcdaefg") == false);
  assert(is_permulation("abccdefg", "bdccaefg") == true);
}
