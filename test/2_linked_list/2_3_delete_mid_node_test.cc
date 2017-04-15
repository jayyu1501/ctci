#include "test_util.h"

class DeleteMidNodeTest : public BaseTest
{
};


TEST_F(DeleteMidNodeTest, delete_null_return_directly)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    delete_mid_node(nullptr);
    EXPECT_EQ(val, to_vector());
}

TEST_F(DeleteMidNodeTest, delete_last_node_return_directly)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    delete_mid_node(get_nth_node(3));
    EXPECT_EQ(val, to_vector());
}

TEST_F(DeleteMidNodeTest, delete_mid_node_return_appropriately)
{
    vector<int> val = {1, 2, 3};
    create_list(val);
    delete_mid_node(get_nth_node(2));
    EXPECT_EQ(vector<int>({1,3}), to_vector());
}

TEST_F(DeleteMidNodeTest, delete_mid_node_with_duplicate_element_return_appropriately)
{
    vector<int> val = {1, 1, 2, 3};
    create_list(val);
    delete_mid_node(get_nth_node(2));
    EXPECT_EQ(vector<int>({1,2,3}), to_vector());
}

TEST_F(DeleteMidNodeTest, delete_mid_element_typical_case_return_appropriately)
{
    vector<int> val = {1, 1, 2, 3, 4, 5, 6};
    create_list(val);
    delete_mid_node(get_nth_node(4));
    EXPECT_EQ(vector<int>({1,1,2,4,5,6}), to_vector());
}
