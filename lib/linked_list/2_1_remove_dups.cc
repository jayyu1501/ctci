#include "linked_list.h"
#include <unordered_set>
using namespace std;

void remove_dups(Node *head)
{
  if (head == NULL)
    {
      return;
    }
  
  Node *p = head;
  Node *d = NULL;
  Node *prev = p;
  unordered_set<int> data_set;
  while(p)
    {
      if (data_set.find(p->data) != data_set.end())
        {
          d = p;
          prev->next = p->next;
          delete d;
        }
      else
        {
          data_set.insert(p->data);
          prev = p;
        }
      p = p->next;
    }
}


