#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char label[100];
    char lexeme[100]; 
    struct Node* children[10];
    int child_count;
} Node;

Node* create_node(const char* label);
Node* create_node_with_lexeme(const char* label, const char* lexeme);
void  add_child(Node* parent, Node* child);
void  print_reverse_tree(Node* root);

#endif