#include "linked_list.h"

void append_to_list(Node *&head, Node *&tail, Node *node)
{
    if (head == nullptr)
    {
        head = node;
    }

    if (tail == nullptr)
    {
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}


Node* partition(Node *head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *p = head;
    Node *small_head = nullptr;
    Node *small_tail = nullptr;
    Node *big_head = nullptr;
    Node *big_tail = nullptr;
    
    while(p)
    {
        if (p->data >= val)
        {
            append_to_list(big_head, big_tail, p);
        }
        else
        {
            append_to_list(small_head, small_tail, p);
        }
        p = p->next;
    }

    if (small_tail)
    {
        if (big_head)
        {
            small_tail->next = big_head;
            big_tail->next = nullptr;
        }
        return small_head;
    } else
    {
        big_tail->next = nullptr;
        return big_head;
    }
}
