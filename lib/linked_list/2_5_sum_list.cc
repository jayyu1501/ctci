#include "linked_list.h"
#include <assert.h> 

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

    // carry
    if (from_prev) {
        Node *newNode = new Node();
        newNode->data = 1;
        newNode->next = nullptr;
        dst->next = newNode;
        from_prev = 0;
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

    if (first) {
        assert(second == nullptr);
        add_node(p, first, from_prev);
    }

    if (second) {
        assert(first == nullptr);
        add_node(p, second, from_prev);
    }
    
    // Same len cause carry
    if (from_prev) {
        Node *newNode = new Node();
        newNode->data = 1;
        newNode->next = nullptr;
        p->next = newNode;
    }
    return head;
}
