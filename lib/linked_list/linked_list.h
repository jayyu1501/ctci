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
