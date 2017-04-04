#include <linked_list/linked_list.h>
#include <gtest/gtest.h>

using namespace std;

static Node *create_linked_list(const vector<int>& nums)
{
  if (nums.size() == 0)
    {
      return NULL;
    }

  Node *head = NULL;
  Node *tail = NULL;
  for(int i = 0; i < nums.size(); i++)
    {
      Node *p = new Node();
      p->data = nums[i];
      p->next = NULL;
      
      if (!head)
        {
          head = p;
        }
      
      if (!tail)
        {
          tail = p;
        }
      else 
        {
          tail->next = p;
          tail = p;
        }
    }
  return head;
}

static void destroy_linked_list(Node* head)
{
  Node *p = head;
  Node *next = NULL;
  while(p)
    {
      next = p->next;
      delete p;
      p = next;
    }
}

static vector<int> dump_data(Node *head)
{
  Node *p = head;
  vector<int> val;
  while(p)
    {
      val.push_back(p->data);
      p = p->next;
    }
  return val;
}


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
