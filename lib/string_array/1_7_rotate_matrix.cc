#include <vector>

using namespace std;

void swap(int& val1, int& val2)
{
  int tmp = val2;
  val2 = val1;
  val1 = tmp;
}

void reverse(vector<int>& row)
{
  int i = 0;
  int j = row.size() - 1;
  while ( j > i)
    {
      swap(row[j], row[i]);
      i++;
      j--;
    }
}


// right rotate 90 degree
void rotate_matrix(vector<vector<int> >& img)
{
  // swap row and col
  for (int k = 0; k < img.size(); k++)
    {
      for(int i = k + 1; i < img[k].size(); i++)
	{
	  swap(img[k][i], img[i][k]);
	}
    }

  // reverse each row
  for (int k = 0; k < img.size(); k++)
    {
      reverse(img[k]);
    }
}

