#include "linked_list.h"

void delete_mid_node(Node *mid)
{
    if (mid == nullptr || mid->next == nullptr)
    {
        return;
    }

    Node *next = mid->next;
    mid->data = next->data;
    mid->next = next->next;

    delete next;
}
