#include <string>
#include <assert.h>

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


int main(int argc, char **argv)
{
  char a[256] = "Mr  John Smith         ";
  urlify(a, 14);
  assert("Mr%20%20John%20Smith" == string(a));
  char b[256] = "MrJohnSmith";
  urlify(b,11);
  assert("MrJohnSmith" == string(b));
  urlify(b, -1);
  assert("MrJohnSmith" == string(b));
  char c[256] = "";
  urlify(c, 0);
  assert(strlen(c) == 0);
}
