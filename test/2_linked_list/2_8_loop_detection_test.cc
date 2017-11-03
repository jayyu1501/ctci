#include "test_util.h"

class LoopDetectionTest : public BaseTest
{

};

TEST_F(LoopDetectionTest, nullptr_return_nullptr)
{
    EXPECT_EQ(nullptr, get_start_of_loop(nullptr));
}

TEST_F(LoopDetectionTest, onenode_return_nullptr)
{
    vector<int> val1 = {1};
    Node* head1 = create_list(val1);
    EXPECT_EQ(nullptr, get_start_of_loop(head1));
}

TEST_F(LoopDetectionTest, two_node_no_circle_return_nullptr)
{
    vector<int> val1 = {1, 2};
    Node* head1 = create_list(val1);
    EXPECT_EQ(nullptr, get_start_of_loop(head1));
}

TEST_F(LoopDetectionTest, many_nodes_no_circle_return_nullptr)
{
    vector<int> val1 = {1, 2, 3, 4, 5};
    Node* head1 = create_list(val1);
    EXPECT_EQ(nullptr, get_start_of_loop(head1));
}

TEST_F(LoopDetectionTest, two_nodes_circle_return_correct_node)
{
    vector<int> val1 = {1, 2, 3, 4, 5};
    Node* head1 = create_list(val1);
    Node* node = get_nth_node(5);
    EXPECT_EQ(5, node->data);
    vector<int> val2 = {6};
    Node* head2 = create_list(val2);
    append(head1, head2);
    append(head1, node);
    EXPECT_EQ(node, get_start_of_loop(head1));
    mHead = nullptr; //avoid delete circle list 
}

TEST_F(LoopDetectionTest, three_nodes_circle_return_correct_node)
{
    vector<int> val1 = {1, 2, 3, 4, 5};
    Node* head1 = create_list(val1);
    Node* node = get_nth_node(3);
    EXPECT_EQ(3, node->data);
    append(head1, node);
    EXPECT_EQ(node, get_start_of_loop(head1));
    mHead = nullptr;  //avoid delete circle list 
}

TEST_F(LoopDetectionTest, many_nodes_circle_return_correct_node)
{
    vector<int> val1 = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head1 = create_list(val1);
    Node* node = get_nth_node(2);
    EXPECT_EQ(2, node->data);
    append(head1, node);
    EXPECT_EQ(node, get_start_of_loop(head1));
    mHead = nullptr;  //avoid delete circle list 
}