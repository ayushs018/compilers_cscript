#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char label[100];
    struct Node* child[10];
    int child_count;
} Node;

Node* create_node(const char* label);
void  add_child(Node* parent, Node* child);
void  print_reverse_tree(Node* root);

#endif