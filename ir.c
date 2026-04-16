#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "ir.h"

Quad code[MAX_CODE];

int codeIndex = 0;
int tempCount = 0;
int labelCount = 0;



char* new_temp()
{
    static char buffer[20];

    sprintf(buffer,"t%d",tempCount++);

    return strdup(buffer);
}


char* new_label()
{
    static char buffer[20];

    sprintf(buffer,"L%d",labelCount++);

    return strdup(buffer);
}



void emit(char *op, char *arg1, char *arg2, char *result)
{
    strcpy(code[codeIndex].op,op);

    strcpy(code[codeIndex].arg1,arg1?arg1:"-");

    strcpy(code[codeIndex].arg2,arg2?arg2:"-");

    strcpy(code[codeIndex].result,result?result:"-");

    codeIndex++;
}



char* gen_expr(Node *node)
{

    if(node==NULL)
        return "";


    /* binary operations */

    if(
        strcmp(node->label,"+")==0 ||
        strcmp(node->label,"-")==0 ||
        strcmp(node->label,"*")==0 ||
        strcmp(node->label,"/")==0 ||
        strcmp(node->label,"%")==0 ||

        strcmp(node->label,"<")==0 ||
        strcmp(node->label,">")==0 ||
        strcmp(node->label,"<=")==0 ||
        strcmp(node->label,">=")==0 ||

        strcmp(node->label,"==")==0 ||
        strcmp(node->label,"!=")==0 ||

        strcmp(node->label,"&&")==0 ||
        strcmp(node->label,"||")==0
    )
    {

        char *left = gen_expr(node->children[0]);

        char *right = gen_expr(node->children[1]);


        char *t = new_temp();

        emit(node->label,left,right,t);

        return t;
    }



    /* assignment */

    if(strcmp(node->label,"=")==0)
    {

        char *rhs = gen_expr(node->children[1]);

        char *lhs = node->children[0]->lexeme;


        emit("=",rhs,"-",lhs);

        return lhs;
    }



    /* unary minus */

    if(strcmp(node->label,"unary-")==0)
    {

        char *v = gen_expr(node->children[0]);

        char *t = new_temp();

        emit("uminus",v,"-",t);

        return t;
    }



    /* identifier */

    if(strcmp(node->label,"id")==0)
        return node->lexeme;



    /* constants */

    if(
        strcmp(node->label,"int")==0 ||
        strcmp(node->label,"float")==0 ||
        strcmp(node->label,"char")==0
    )
        return node->lexeme;



    return "";
}




void generate_ir(Node *node)
{

    if(node==NULL)
        return;



    /* assignment statement */

    if(strcmp(node->label,"=")==0)
    {
        gen_expr(node);
        return; 
    }
    /* if */
    if(strcmp(node->label,"if")==0)
    {
        char *cond = gen_expr(node->children[0]);
        char *L = new_label();
        emit("IF_FALSE",cond,"-",L);
        generate_ir(node->children[1]);
        emit("LABEL","-","-",L);
        return;
    }
    /* if else */
    if(strcmp(node->label,"if-else")==0)
    {
        char *cond = gen_expr(node->children[0]);
        char *L1 = new_label();
        char *L2 = new_label();
        emit("IF_FALSE",cond,"-",L1);
        generate_ir(node->children[1]);
        emit("GOTO","-","-",L2);
        emit("LABEL","-","-",L1);
        generate_ir(node->children[2]);
        emit("LABEL","-","-",L2);
        return; 
    }
    /* while */
    if(strcmp(node->label,"while")==0)
    {
        char *start = new_label();
        char *end = new_label();
        emit("LABEL","-","-",start);
        char *cond = gen_expr(node->children[0]);
        emit("IF_FALSE",cond,"-",end);
        generate_ir(node->children[1]);
        emit("GOTO","-","-",start);
        emit("LABEL","-","-",end);
        return; 
    }
    /* for loop */
    if(strcmp(node->label,"for")==0)
    {
        char *start = new_label();
        char *end = new_label();
        /* initialization */
        generate_ir(node->children[0]);
        emit("LABEL","-","-",start);
        /* condition */
        char *cond = gen_expr(node->children[1]);
        emit("IF_FALSE",cond,"-",end);
        /* body */
        generate_ir(node->children[3]);
        /* update */
        generate_ir(node->children[2]);
        emit("GOTO","-","-",start);
        emit("LABEL","-","-",end);
        return;
    }

    /* recursive traversal */
    for(int i=0;i<node->child_count;i++)
        generate_ir(node->children[i]);

}


void print_ir_to_file(const char *filename)
{
    FILE *fp = fopen(filename,"w");

    if(!fp)
    {
        printf("Error creating TAC file\n");
        return;
    }

    fprintf(fp,"\n================= THREE ADDRESS CODE =================\n\n");

    fprintf(fp,"%-12s %-12s %-12s %-12s\n",
            "op","arg1","arg2","result");

    for(int i=0;i<codeIndex;i++)
    {
        fprintf(fp,"%-12s %-12s %-12s %-12s\n",
            code[i].op,
            code[i].arg1,
            code[i].arg2,
            code[i].result
        );
    }

    fclose(fp);
}