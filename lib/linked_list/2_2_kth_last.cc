#include "linked_list.h"


Node *kth_last(int k, Node *head)
{
  if (k <= 0)
    {
      return nullptr;
    }

  Node *last = head;
  Node *kth = nullptr;
  
  int steps = 0;

  while(last && steps < k)
    {
      last = last->next;
      steps++;
    }
  
  if (steps == k)
    {
      kth = head;
    }
  
  while(last)
    {
      last = last->next;
      kth = kth->next;
    }

  return kth;
}
