#include "test_util.h"

TEST(REMOVE_DUPS, NULL)
{
  Node* head = NULL;
  remove_dups(head);
  EXPECT_EQ(NULL, head);
}

TEST(REMOVE_DUPS, EMPTY)
{
  vector<int> val = {};
  Node *head = create_linked_list(val);
  remove_dups(head);
  vector<int> ret = dump_data(head);
  EXPECT_EQ(val, ret);
  destroy_linked_list(head);
}


TEST(REMOVE_DUPS, NO_DUPS)
{
  vector<int> val = { 1, 2, 3, 4, 7, 9, 22};
  Node *head = create_linked_list(val);
  remove_dups(head);
  vector<int> ret = dump_data(head);
  EXPECT_EQ(val, ret);
  destroy_linked_list(head);
}

TEST(REMOVE_DUPS, ALL_DUPS)
{
  vector<int> val = { 1, 1, 1, 1, 1, 1, 1};
  Node *head = create_linked_list(val);
  remove_dups(head);
  vector<int> ret = dump_data(head);
  vector<int> expected = {1};
  EXPECT_EQ(expected, ret);
  destroy_linked_list(head);
}

TEST(REMOVE_DUPS, Some_DUPS)
{
  vector<int> val = { 1, 2, 5, 2, 5, 7, 2};
  Node *head = create_linked_list(val);
  remove_dups(head);
  vector<int> ret = dump_data(head);
  vector<int> expected = {1, 2, 5, 7};
  EXPECT_EQ(expected, ret);
  destroy_linked_list(head);
}
