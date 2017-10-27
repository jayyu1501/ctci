#include "test_util.h"

class SumListReverseTest : public BaseTest
{
};

TEST_F(SumListReverseTest, nullptr_return_nullptr)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    EXPECT_EQ(nullptr, sum_list_reverse(nullptr, mHead));
}

TEST_F(SumListReverseTest, empty_return_nullptr)
{
    vector<int> val1 = {1, 2, 3};
    Node* head1 = create_list(val1);
    vector<int> val2 = {};
    Node* head2 = create_list(val2);

    EXPECT_EQ(nullptr, sum_list_reverse(head1, head2));
}


TEST_F(SumListReverseTest, same_len_normal)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9, 2};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list_reverse(head1, head2);
    vector<int> result = {1, 3, 0, 8};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListReverseTest, different_len_normal)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list_reverse(head1, head2);
    vector<int> result = {7, 7, 5};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListReverseTest, same_len_more_digits)
{
    vector<int> val1 = {7, 1, 6};
    Node* head1 = create_list(val1);
    vector<int> val2 = {5, 9, 5};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list_reverse(head1, head2);
    vector<int> result = {1, 3, 1, 1};
    EXPECT_EQ(result, dump_data(newHead));
}

TEST_F(SumListReverseTest, different_len_more_digits)
{
    vector<int> val1 = {9, 1, 9};
    Node* head1 = create_list(val1);
    vector<int> val2 = {9, 9};
    Node* head2 = create_list(val2);
    Node* newHead = sum_list_reverse(head1, head2);
    vector<int> result = {1, 0, 1, 8};
    EXPECT_EQ(result, dump_data(newHead));
}