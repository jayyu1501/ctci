#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_PALINDROME_PERMUTATION, ALL)
{
  assert(is_palindrome_permutation(""));
  assert(is_palindrome_permutation("    "));
  assert(!is_palindrome_permutation("abc"));
  assert(is_palindrome_permutation("Tact Coa"));
}
