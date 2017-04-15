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
