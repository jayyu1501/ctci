#include <unordered_map>
#include <iostream>

using namespace std;

bool is_permulation(const string& strA, const string& strB)
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
