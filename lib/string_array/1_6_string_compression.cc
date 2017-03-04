#include <string>
#include <sstream>

using namespace std;

string compress_string(const string& src)
{
  if (src.empty())
    {
      return src;
    }

  stringstream ss;
  int start = 0;
  for(int i = 1;i < src.length(); i++)
    {
      if (src[i] != src[start])
	{
	  ss << src[start];
	  ss << (i - start);
	  start = i;
	}
    }
  
  if (start != (src.length() - 1))
    {
      ss << src[start];
      ss << (src.length() - start);
    }

  string target = ss.str();
  if (target.length() >= src.length())
    {
      return src;
    }
  else
    {
      return target;
    }
}


