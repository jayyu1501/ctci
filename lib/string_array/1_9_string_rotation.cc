#include <string>
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

