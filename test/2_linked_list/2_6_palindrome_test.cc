#include "test_util.h"

class PalindromeTest : public BaseTest
{

};

TEST_F(PalindromeTest, null_false)
{
    EXPECT_FALSE(is_palindrome(nullptr));
}

TEST_F(PalindromeTest, empty_true)
{
    vector<int> val = {};
    Node* head = create_list(val);
    EXPECT_FALSE(is_palindrome(head));
}

TEST_F(PalindromeTest, OneNode_true)
{
    vector<int> val = {1};
    Node* head = create_list(val);
    EXPECT_TRUE(is_palindrome(head));
}

TEST_F(PalindromeTest, 2Nodes_SameCharacters_True)
{
    vector<int> val = {1, 1};
    Node* head = create_list(val);
    EXPECT_TRUE(is_palindrome(head));
}

TEST_F(PalindromeTest, 2Nodes_DifferentCharacters_False)
{
    vector<int> val = {1, 2};
    Node* head = create_list(val);
    EXPECT_FALSE(is_palindrome(head));
}

TEST_F(PalindromeTest, 3Nodes_SameCharacters_True)
{
    vector<int> val = {1,2,1};
    Node* head = create_list(val);
    EXPECT_TRUE(is_palindrome(head));
}

TEST_F(PalindromeTest, 3Nodes_DifferentCharacters_False)
{
    vector<int> val = {1, 2, 3};
    Node* head = create_list(val);
    EXPECT_FALSE(is_palindrome(head));
}

TEST_F(PalindromeTest, OddNodes_Same_True)
{
    vector<int> val = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    Node* head = create_list(val);
    EXPECT_TRUE(is_palindrome(head));
}

TEST_F(PalindromeTest, EvenNodes_Same_True)
{
    vector<int> val = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    Node* head = create_list(val);
    EXPECT_TRUE(is_palindrome(head));
}

TEST_F(PalindromeTest, OddNodes_Different_False)
{
    vector<int> val = {1, 2, 3, 1, 2};
    Node* head = create_list(val);
    EXPECT_FALSE(is_palindrome(head));
}

TEST_F(PalindromeTest, EvenNodes_Different_False)
{
    vector<int> val = {1, 2, 1, 2};
    Node* head = create_list(val);
    EXPECT_FALSE(is_palindrome(head));
}