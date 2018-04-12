#include "linked_list.h"
#include <unordered_set>
using namespace std;

void remove_dups(Node *head)
{
  if (head == NULL)
  {
    return;
  }
  
  Node *prev = nullptr;
  Node *d = nullptr;
  unordered_set<int> data_set;
  while(head)
    {
      if (data_set.find(head->data) != data_set.end())
      {
          prev->next = head->next;
          delete head;
          head = prev;
      }
      else
      {
        data_set.insert(head->data);
        prev = head;
      }
      head = head->next;
    }
}


