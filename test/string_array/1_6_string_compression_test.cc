#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_COMPRESS_STRING, ALL)
{
  assert(compress_string("") == "");
  assert(compress_string("aa") == "aa");
  assert(compress_string("aaa") == "a3");
  assert(compress_string("abc") == "abc");
  assert(compress_string("aabcccccaaa") == "a2b1c5a3");
}
