#include "linked_list.h"
#include <assert.h> 

Node* reverse(Node *head)
{
    assert(head);
    if (!head || !head->next) {
        return head;
    }

    Node* prev = head;
    Node* next = head->next;
    head->next = nullptr; // change last node to point to null;
    while(next) {
        Node* tmp = next->next;
        next->next = prev;
        prev = next;
        next = tmp;
    }

    return prev;
}

Node* sum_list_reverse(Node* first, Node* second)
{
    Node* head = nullptr;
    Node* p = nullptr;
    if (first == nullptr || second == nullptr)
    {
        return nullptr;
    }

    first = reverse(first);
    second = reverse(second);
    Node* newHead = sum_list(first, second);
    Node* ret = reverse(newHead);
    return ret;
}
