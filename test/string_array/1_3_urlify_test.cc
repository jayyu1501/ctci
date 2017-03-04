#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_URLIFY, ALL)
{
  char a[256] = "Mr  John Smith         ";
  urlify(a, 14);
  assert("Mr%20%20John%20Smith" == string(a));
  char b[256] = "MrJohnSmith";
  urlify(b,11);
  assert("MrJohnSmith" == string(b));
  urlify(b, -1);
  assert("MrJohnSmith" == string(b));
  char c[256] = "";
  urlify(c, 0);
  assert(strlen(c) == 0);
}
