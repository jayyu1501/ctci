#include <gtest/gtest.h>
#include <string_array/string_array.h>

void print_matrix(vector<vector<int> >& matrix)
{
  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}


TEST(TEST_ZERO_MATRIX, ALL)
{
  vector<vector<int> > m1 = { { 1, 2, 3},
			      { 4, 5, 6},
			      { 7, 8, 9} };
  
  vector<vector<int> > ret_m1 = m1;
  zero_matrix(m1);
  print_matrix(m1);
  assert(m1 == ret_m1);

  vector<vector<int> > m2 = { { 1, 2, 3},
			      { 0, 5, 6},
			      { 7, 8, 9} };
  
  vector<vector<int> > ret_m2 = { { 0, 0, 0},
				  { 0, 0, 0},
				  { 0, 0, 0} };
  zero_matrix(m2);
  print_matrix(m2);
  assert(m2 == ret_m2);
}