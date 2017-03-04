#include <vector>
#include <iostream>
using namespace std;

void fill_zero(vector<vector<int> >& matrix)
{
  for(int i = 0; i < matrix.size(); i++)
  {
    fill(matrix[i].begin(), matrix[i].end(), 0);
  }
}

void zero_matrix(vector<vector<int> >& matrix)
{
  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix[i].size(); j++)
    {
      if (!matrix[i][j])
      {
	fill_zero(matrix);
	return;
      }
    }
  }
}

