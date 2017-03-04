#include <string>
#include <assert.h>
using namespace std;

bool is_substring(const string& str, const string& sub)
{
  return str.find(sub) != string::npos;
}

bool is_string_rotation(const string& s1, const string& s2)
{
  if (s1.length() != s2.length())
    {
      return false;
    }

  if (s1.length() == 0)
    {
      return true;
    }
  
  if (s1 == s2)
    {
      return true;
    }
  
  int len = s1.length();
  /*
   * Try to find the correct position of s2[0] in s1 by i
   *
   */
  int i = 0;
  int pos = -1;
  while(i < len)
    {
      if (s1[i] != s2[0])
	{
	  i++;
	}
      else
	{
	  int k = i;
	  int j = 0;
	  do
	    {
	      k = (k+1) % len;
	      j++;
	    } while(k != i && s1[k] == s2[j]);

	  if (k == i)
	    {
	      return true;
	    }
	  else
	    {
	      i++;
	    }
	}
    }
  return false;
}

int main(int argc, char **argv)
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
