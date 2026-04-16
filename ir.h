#ifndef IR_H
#define IR_H

#define MAX_CODE 1000

typedef struct
{
    char op[20];
    char arg1[50];
    char arg2[50];
    char result[50];

} Quad;

extern Quad code[MAX_CODE];
extern int codeIndex;

char* new_temp();
char* new_label();

void emit(char *op, char *arg1, char *arg2, char *result);

void generate_ir(Node *node);

void print_ir();

#endif