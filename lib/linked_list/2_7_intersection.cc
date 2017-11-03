#include "linked_list.h"

unsigned int get_length(const Node* head)
{
    unsigned int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}


const Node* get_intersection(const Node* first, const Node* second)
{
    if (first == nullptr || second == nullptr) 
    {
        return nullptr;
    }

    unsigned int firstLen = get_length(first);
    unsigned int secondLen = get_length(second);

    if (firstLen > secondLen) {
        unsigned int skipCount = firstLen - secondLen;
        while(first != nullptr && skipCount-- > 0) 
        {
            first = first->next;
        }
    }
    else if (secondLen > firstLen)
    {
        unsigned int skipCount = secondLen - firstLen;
        while(second != nullptr && skipCount-- > 0) 
        {
            second = second->next;
        }
    }

    // Now first and second has the same length
    while(first && second) 
    {
        if (first == second) {
            return first;
        }
        first = first->next;
        second = second->next;
    }
    return nullptr;
}