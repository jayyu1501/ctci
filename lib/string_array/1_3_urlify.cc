#include <string>

using namespace std;

void urlify(char* str, int n)
{
  if (n <= 0)
    {
      return;
    }
  int space_count = 0;
  for (int i = 0; i < n; i++)
    {
      if (str[i] == ' ')
	{
	  space_count++;
	}
    }

  if (space_count <= 0 )
    {
      return;
    }

  int newSize = n + space_count * 2;
  int k = newSize - 1;
  for (int j = n - 1; j >= 0; j--)
  {
    if (str[j] != ' ')
      {
	str[k] = str[j];
	k--;
      }
    else 
      {
	str[k - 2] = '%';
	str[k - 1] = '2';
	str[k] = '0';
	k -= 3;
      }
  }
  str[newSize] = '\0';
}

