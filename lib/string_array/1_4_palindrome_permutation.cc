#include <string>
#include <unordered_map>

using namespace std;

#define CHAR_NUM 26

bool is_palindrome_permutation(const string& str)
{
  int freq[CHAR_NUM] = {0};
  for(int i = 0; i < str.length(); i++)
    {
      if (str[i] != ' ')
	{
	  freq[tolower(str[i])-'a']++;
	}
    }
  int odd_count = 0;
  for(int i = 0; i < CHAR_NUM; i++)
    {
      if (freq[i] % 2 == 1)
	{
	  odd_count++;
	  if (odd_count > 1)
	    {
	      return false;
	    }
	}
    }
  return true;
}

