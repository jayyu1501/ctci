#include "linked_list.h"

void add_node(Node *dst, const Node* src, int& from_prev)
{
    while (src) {
        int sum = src->data + from_prev;
        Node *node = new Node({sum % 10, nullptr});
        from_prev = sum >=10 ? 1 : 0;
        src = src->next;
        dst->next = node;
        dst = node;
    }
}

Node* sum_list(const Node* first, const Node* second)
{
    Node* head = nullptr;
    Node* p = nullptr;
    if (first == nullptr || second == nullptr)
    {
        return nullptr;
    }

    int from_prev = 0;
    while (first != nullptr && second != nullptr)
    {
        Node* node = new Node();
        node->next = nullptr;
        int sum = first->data + second->data + from_prev;
        node->data = sum % 10;
        from_prev = sum >=10 ? 1 : 0;

        if(p == nullptr)
        {
            head = node;
            p = node;
        } else{
            p->next = node;
            p = node;
        }

        first = first->next;
        second = second->next;
    }

    add_node(p, first, from_prev);
    add_node(p, second, from_prev);

    return head;
}
