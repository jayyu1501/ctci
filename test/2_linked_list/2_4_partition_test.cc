#include "test_util.h"

class PartitionTest : public BaseTest
{
};


TEST_F(PartitionTest, null_return_null)
{
    EXPECT_EQ(nullptr, partition(mHead, 100));
}

TEST_F(PartitionTest, empty_return_empty)
{
    vector<int> val = {};
    create_list(val);
    mHead = partition(mHead, 100);
    EXPECT_EQ(val, to_vector());
}

TEST_F(PartitionTest, not_contained_very_big)
{
    vector<int> val = {3, 5, 8, 5, 10, 2, 1};
    create_list(val);
    mHead = partition(mHead, 100);
    EXPECT_EQ(val, to_vector());
}

TEST_F(PartitionTest, not_contained_very_small)
{
    vector<int> val = {3, 5, 8, 5, 10, 2, 1};
    create_list(val);
    mHead = partition(mHead, -100);
    EXPECT_EQ(val, to_vector());
}

TEST_F(PartitionTest, contained_middle)
{
    vector<int> val = {3, 5, 8, 5, 10, 2, 1};
    create_list(val);
    mHead = partition(mHead, 5);
    vector<int> expect = { 3, 2, 1, 5, 8, 5, 10 };
    EXPECT_EQ(expect, to_vector());
}

TEST_F(PartitionTest, not_contained_middle)
{
    vector<int> val = {3, 5, 8, 5, 10, 2, 1};
    create_list(val);
    mHead = partition(mHead, 6);
    vector<int> expect = { 3, 5, 5, 2, 1, 8, 10 };
    EXPECT_EQ(expect, to_vector());
}
