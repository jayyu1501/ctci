#include "test_util.h"

class IntersectionTest : public BaseTest
{

};

TEST_F(IntersectionTest, two_nullptrs_return_nullptr)
{
    EXPECT_EQ(nullptr, get_intersection(nullptr, nullptr));
}

TEST_F(IntersectionTest, one_nullptr_return_nullptr)
{
    vector<int> val1 = {};
    Node* head1 = create_list(val1);
    vector<int> val2 = {1, 2, 3};
    Node* head2 = create_list(val2);
    EXPECT_EQ(nullptr, get_intersection(head1, head2));
}

TEST_F(IntersectionTest, same_value_not_same_reference_return_nullptr)
{
    vector<int> val1 = {1, 2, 3};
    Node* head1 = create_list(val1);
    vector<int> val2 = {1, 2, 3};
    Node* head2 = create_list(val2);
    EXPECT_EQ(nullptr, get_intersection(head1, head2));
}

TEST_F(IntersectionTest, same_reference_return_node)
{
    vector<int> val1 = {1, 2, 3, 4, 5};
    Node* head1 = create_list(val1);
    Node* node = get_nth_node(3);
    vector<int> val2 = {5, 6, 7};
    Node* head2 = create_list(val2);
    append(head2, node);
    EXPECT_EQ(node, get_intersection(head1, head2));
}


TEST_F(IntersectionTest, same_reference_on_last_node_return_node)
{
    vector<int> val1 = {1, 2, 3, 4, 5};
    Node* head1 = create_list(val1);
    Node* node = get_nth_node(5);
    vector<int> val2 = {1, 2, 3, 5, 5, 5};
    Node* head2 = create_list(val2);
    append(head2, node);
    EXPECT_EQ(node, get_intersection(head1, head2));
}