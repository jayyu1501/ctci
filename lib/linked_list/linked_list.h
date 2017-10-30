#pragma once

struct Node;

struct Node
{
  int data;
  Node *next;
};

//2_1 remove dups
void remove_dups(Node *);
void remove_dups_nobuffer(Node *);

//2_2 kth_last
Node *kth_last(int k, Node *);


//2_3 delete middle nodes
void delete_mid_node(Node *mid);

//2_4 partition
Node* partition(Node *head, int val);

//2_5 sumlist
Node* sum_list(const Node* first, const Node* second);
Node* sum_list_reverse(Node* first, Node* second);
Node* reverse(Node *head);

//2_6 palindrome
bool is_palindrome(Node* head);
