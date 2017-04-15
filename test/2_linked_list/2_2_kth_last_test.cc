#include "test_util.h"


class KthLastTest : public BaseTest
{
};

TEST_F(KthLastTest, NegativeK_Return_nullptr)
{
    vector<int> val = {1};
    create_list(val);
    EXPECT_EQ(nullptr, kth_last(-1, mHead));
}

TEST_F(KthLastTest, ZeroK_Return_nullptr)
{
    vector<int> val = {1};
    create_list(val);
    EXPECT_EQ(nullptr, kth_last(0, mHead));
}


TEST_F(KthLastTest, OneK_Return_last)
{
    vector<int> val = {999};
    create_list(val);
    EXPECT_EQ(999, kth_last(1, mHead)->data);
}

TEST_F(KthLastTest, NormalK_Return_Normal)
{
    vector<int> val = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create_list(val);
    EXPECT_EQ(5, kth_last(5, mHead)->data);
}


TEST_F(KthLastTest, TooBigK_Return_nullptr)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    EXPECT_EQ(nullptr, kth_last(4, mHead));
    EXPECT_EQ(1, kth_last(3, mHead)->data);    
}
