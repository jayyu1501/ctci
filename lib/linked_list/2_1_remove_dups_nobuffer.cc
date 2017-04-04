#include "linked_list.h"
#include <unordered_set>
using namespace std;

void remove_dups_nobuffer(Node *head)
{
  if (head == NULL)
    {
      return;
    }
  
  Node *pilot = head;
  while(pilot)
    {
      Node *p = pilot->next;
      Node *last = pilot;
      while(p)
        {
          while(p && pilot->data == p->data)
            {
              Node *tmp = p;
              p = p->next;
              delete tmp;
            }
          
          last->next = p;
          last = p;
          if (p)
          {
              p = p->next;
          }
        }
      pilot = pilot->next;
    }
}


