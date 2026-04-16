#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* create_node_with_lexeme(const char* label, const char* lexeme)
{
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->label, label);
    if (lexeme)
        strcpy(n->lexeme, lexeme);
    else
        strcpy(n->lexeme, "");
    n->child_count = 0;
    return n;
}

Node* create_node(const char* label)
{
    return create_node_with_lexeme(label, NULL);
}

void add_child(Node* parent, Node* child)
{
    if (child == NULL) return;
    parent->children[parent->child_count++] = child;
}

void print_reverse_tree(Node* root)
{
    if(root == NULL) return;
    for(int i = 0; i < root->child_count; i++)
        print_reverse_tree(root->children[i]);
    printf("%s\n", root->label);
}