#include <iostream>
#include <string>
#include <assert.h>



using namespace std;

bool is_unique(string str)
{
  int i = 0;
  int bits[4] = {0};
  while(i < str.length())
  {
    int val = (int)str[i++];
    int bit_val = bits[val/32] & (1 << (val % 32)); 
    if (bit_val != 0)
    {
      return false;
    } else {
      bits[val/32] |= (1 << (val % 32));
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  assert(is_unique(""));
  assert(is_unique("a"));
  assert(!is_unique("aa"));
  assert(is_unique("abcdefgABCHIJZ"));
  assert(!is_unique("abcdefgABCHIJZa"));
  std::cout << "Done:" << argv[0] << std::endl;
}
