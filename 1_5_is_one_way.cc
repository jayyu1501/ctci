#include <assert.h>
//#include <unordered_set>
#include <string>
using namespace std;

enum LENGTH_SITUATION 
  {
    SAME,
    A_LONG,
    B_LONG
  };


bool is_one_way(const string& strA, const string& strB)
{
  int dist = 0;
  int lenDiff = (int)strA.length() - (int)strB.length();
  if (lenDiff > 1 || lenDiff < -1)
    {
      return false;
    }
  
  LENGTH_SITUATION situ = SAME;
  if (strA.length() > strB.length())
    {
      situ = A_LONG;
    }
  else if (strA.length() < strB.length())
    {
      situ = B_LONG;
    }
  

  int i = 0;
  int j = 0;
  while(i < strA.length() && j < strB.length())
    {
      if (strA[i] != strB[j])
	{
	  switch (situ)
	    {
	  case SAME:
	    {
	      i++;
	      j++;
	      dist++;
	    }
	  break;
	case A_LONG:
	  {
	    dist++;
	    i++;
	  }
	  break;
       case B_LONG:
	  {
	    dist++;
	    j++;
	  }
	  break;
	}
      }
      else
	{
	  i++;
	  j++;
	}

    }

  return dist <= 1;
}


int main(int argc, char **argv)
{
  assert(is_one_way("pale", "ple"));
  assert(is_one_way("", ""));
  assert(is_one_way("pales", "pale"));
  assert(is_one_way("pale", "bale"));
  assert(!is_one_way("pale", "bake"));
  assert(is_one_way("pale", "pale"));
}

