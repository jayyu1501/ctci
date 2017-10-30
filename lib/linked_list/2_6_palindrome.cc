#include "linked_list.h"

bool is_palindrome(Node* head)
{
    if (head == nullptr) {
        return false;
    }

    Node* p = head;
    int len = 0;
    while(p) 
    {
        len++;
        p = p->next;
    }

    if (len == 0) 
    {
        return false;    
    }
    else if (len == 1) //empty or just one node
    {
        return true;
    }

    int second_seq_start_from = (len % 2 == 0 ? len/2 : len/2 + 1); 
    int count = 0;
    p = head;
    while(p && count < second_seq_start_from) 
    {
        p = p->next;
        count++;
    }

    // Now p points to the start of second sequence
    Node *second = reverse(p);

    // check whether head and second is same for len/2 length
    Node *p1 = head;
    Node *p2 = second;
    count = 0;
    while(p1 && p2 && count < len/2) 
    {
        if (p1->data != p2->data)
        {
            return false;
        }    
        p1 = p1->next;
        p2 = p2->next;
        count++;
    }

    if (count != len/2) 
    {
        return false;
    }

    //reverse back to origin order
    reverse(second);
    return true;
}
