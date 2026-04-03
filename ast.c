#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* create_node(const char* label)
{
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->label, label);
    n->child_count = 0;
    return n;
}

void add_child(Node* parent, Node* child)
{
    parent->child[parent->child_count++] = child;
}

void print_reverse_tree(Node* root)
{
    if(root == NULL) return;
    for(int i = 0; i < root->child_count; i++)
        print_reverse_tree(root->child[i]);
    printf("%s\n", root->label);
}