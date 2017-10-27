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


TEST_F(SumListTest, same_len_normal)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9, 2};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list(head1, head2);
    vector<int> result = {2, 1, 9};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListTest, different_len_normal)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list(head1, head2);
    vector<int> result = {2, 1, 7};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListTest, same_len_more_digits)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9, 5};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list(head1, head2);
    vector<int> result = {2, 1, 2, 1};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListTest, different_len_more_digits)
{
    vector<int> val1 = {9, 1, 9};
    Node* head1 = create_list(val1);
    vector<int> val2 = {2, 9};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list(head1, head2);
    vector<int> result = {1, 1, 0, 1};
    EXPECT_EQ(result, dump_data(newHead));
}