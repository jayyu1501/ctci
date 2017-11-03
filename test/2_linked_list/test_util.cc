#include <linked_list/linked_list.h>
#include "test_util.h"
#include <cassert>

using namespace std;

Node *create_linked_list(const vector<int>& nums)
{
  if (nums.size() == 0)
    {
      return nullptr;
    }

  Node *head = nullptr;
  Node *tail = nullptr;
  for(int i = 0; i < nums.size(); i++)
    {
      Node *p = new Node();
      p->data = nums[i];
      p->next = nullptr;
      
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

void destroy_linked_list(Node* head)
{
  Node *p = head;
  Node *next = nullptr;
  while(p)
    {
      next = p->next;
      delete p;
      p = next;
    }
}

vector<int> dump_data(Node *head)
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

void append(Node* left, Node* right)
{
  if (!left || !right)
  {
    return;
  }
  Node *prev = nullptr;
  Node *next = left;
  while(next)
  {
    prev = next;
    next = next->next;
  }
  assert(prev);
  prev->next = right;
}
