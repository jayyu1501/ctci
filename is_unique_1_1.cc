#include <iostream>
#include <string>


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
  cout << is_unique("abcdefgABCHIJZ") << endl;
  cout << is_unique("abcdefgABCHIJZa") << endl;
}
