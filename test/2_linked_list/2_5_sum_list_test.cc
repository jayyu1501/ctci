#include "test_util.h"

class SumListTest : public BaseTest
{
};

TEST_F(SumListTest, nullptr_return_nullptr)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    EXPECT_EQ(nullptr, sum_list(nullptr, mHead));
}

TEST_F(SumListTest, empty_return_nullptr)
{
    vector<int> val1 = {1, 2, 3};
    Node* head1 = create_list(val1);
    vector<int> val2 = {};
    Node* head2 = create_list(val2);

    EXPECT_EQ(nullptr, sum_list(head1, head2));
}

TEST_F(SumListTest, empty_return_nullptr)
{
    vector<int> val1 = {1, 2, 3};
    Node* head1 = create_list(val1);
    vector<int> val2 = {};
    Node* head2 = create_list(val2);

    EXPECT_EQ(nullptr, sum_list(head1, head2));
}