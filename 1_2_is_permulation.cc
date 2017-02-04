#include <unordered_map>
#include <iostream>
#include <assert.h>

using namespace std;

bool is_permulation(string strA, string strB)
{
  if (strA.length() != strB.length())
  {
    return false;
  }
  
  unordered_map<char, int> stat;
  for(int i = 0; i < strA.length(); i++)
  {
    stat[strA[i]]++;
  } 

  for (int j = 0; j < strB.length(); j++)
    {
      if (stat.find(strB[j]) == stat.end())
	{
	  return false;
	}
      else
	{
	  if (stat[strB[j]] <= 0)
	    {
	      return false;
	    }
	  else
	    {
	      stat[strB[j]]--;
	    }
	}
    }
  return true;
}



int main(int argc, char **argv)
{
  assert(is_permulation("", "a") == false);
  assert(is_permulation("a", "a") == true);
  assert(is_permulation("abcdefg", "bdcaefg") == true);
  assert(is_permulation("abccdefg", "bdcdaefg") == false);
  assert(is_permulation("abccdefg", "bdccaefg") == true);
}

