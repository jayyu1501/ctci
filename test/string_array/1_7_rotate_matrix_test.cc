#include <gtest/gtest.h>
#include <string_array/string_array.h>


TEST(TEST_ROTATE_MATRIX, ALL)
{
  vector<vector<int> > img1 = { {11,12,13},
			        {21,22,23},
			        {31,32,33} };

  rotate_matrix(img1);
  
  vector<vector<int> > ret_img1 = { { 31, 21, 11},
				    { 32, 22, 12},
				    { 33, 23, 13}};
  assert(img1 == ret_img1);

  vector<vector<int> > img2;
  vector<vector<int> > ret_img2;
  rotate_matrix(img2);
  assert(img2 == ret_img2);

}
