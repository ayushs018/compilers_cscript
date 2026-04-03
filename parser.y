%{
#include "ast.h"
#include "errors.h"
Node* root;
void print_parsing_table(); 

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;

extern int yyline;
extern int yycol;
extern int yyprevline;
extern int yyprevcol;
extern int yyprevendcol;
extern char *yytext;

void yyerror(const char *s);
%}

/* TOKENS */

%token VAR FUNC EXTERN STRUCT
%token IF ELSE FOR WHILE DO SWITCH CASE DEFAULT
%token BREAK CONTINUE RETURN SIZEOF

%token IDENTIFIER
%token INT_CONST FLOAT_CONST CHAR_CONST STRING_LITERAL

%token INC_OP DEC_OP PTR_OP
%token AND_OP OR_OP
%token LE_OP GE_OP EQ_OP NE_OP
%token SHL_OP SHR_OP

/* PRECEDENCE */

%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left SHL_OP SHR_OP
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%right '!' '~'
%left INC_OP DEC_OP
%right '='
%nonassoc IFX
%nonassoc ELSE
%union{
    Node* node;
}

%type <node> program global_list global
%type <node> var_decl var_init_list var_init
%type <node> func_decl param_list param
%type <node> block statement_list statement
%type <node> assignment lvalue
%type <node> expression logical_or_expr logical_and_expr
%type <node> bitwise_or_expr bitwise_xor_expr bitwise_and_expr
%type <node> equality_expr relational_expr shift_expr
%type <node> additive_expr multiplicative_expr unary_expr
%type <node> postfix_expr primary_expr
%type <node> argument_list expression_list
%type <node> loop_stmt switch_stmt case_list case_block

%%

program:
      global_list
      {
        root = create_node("program");
        add_child(root,$1);
      }
    ;

global_list:
      global_list global
      {
        $$ = create_node("global_list");
        add_child($$, $1); 
        add_child($$, $2);
      }
    | 
      global {
        $$ = $1; 
      }
    ;

global:
      var_decl        { $$ = $1; }
    | func_decl       { $$ = $1; }
    | struct_decl     { $$ = create_node("struct_decl"); }
    | extern_decl     { $$ = create_node("extern_decl"); }
    ;


/* declarations */

extern_decl:
      EXTERN VAR IDENTIFIER ';'
    ;

struct_decl:
      STRUCT IDENTIFIER '{' var_decl_list '}' ';'
    ;

var_decl_list:
      var_decl_list var_decl
    | var_decl
    ;

var_decl:
      VAR var_init_list ';' 
      {
        $$ = create_node("var_decl");
        add_child($$, $2);
      }
    ;

var_init_list:
      var_init_list ',' var_init
    | var_init
    ;

var_init:
      IDENTIFIER
        { $$ = create_node("var_init"); }
    | IDENTIFIER '=' expression
        { $$ = create_node("var_init="); add_child($$, $3); }
    | IDENTIFIER '[' INT_CONST ']'
        { $$ = create_node("var_init[]"); }
    | IDENTIFIER '[' INT_CONST ']' '=' '{' expression_list '}'
        { $$ = create_node("var_init[]="); add_child($$, $7); }
    ;


/* functions */

func_decl:
      FUNC IDENTIFIER '(' param_list ')' block
        { $$ = create_node("func_decl"); add_child($$, $4); add_child($$, $6); }
    | FUNC IDENTIFIER '(' ')' block
        { $$ = create_node("func_decl"); add_child($$, $5); }
    ;

param_list:
      param_list ',' param
    | param
    ;

param:
      VAR IDENTIFIER  { $$ = create_node("param"); }
    ;


/* blocks */

block:
      '{' statement_list '}'
        { $$ = create_node("block"); add_child($$, $2); }
    ;


statement_list:
      statement_list statement
      { $$ = create_node("stmt_list"); add_child($$,$1); add_child($$,$2); }
    | statement
    { $$ = $1; }
    ;

/* dangling else resolved */

statement:
      var_decl                  { $$ = $1; }
    | assignment ';'            { $$ = $1; }
    | expression ';'            { $$ = $1; }
    | block                     { $$ = $1; }
    | loop_stmt                 { $$ = $1; }
    | switch_stmt               { $$ = $1; }
    | BREAK ';'                 { $$ = create_node("break"); }
    | CONTINUE ';'              { $$ = create_node("continue"); }
    | RETURN expression ';'
        { $$ = create_node("return"); add_child($$, $2); }
    | IF '(' expression ')' statement %prec IFX
        { $$ = create_node("if"); add_child($$, $3); add_child($$, $5); }
    | IF '(' expression ')' statement ELSE statement
        { $$ = create_node("if-else"); add_child($$, $3); add_child($$, $5); add_child($$, $7); }
    | error ';'               { $$ = create_node("error"); yyerrok; yyclearin; }
    | error '}'               { $$ = create_node("error"); yyerrok; yyclearin; }
    ;


/* assignment */

assignment:
      lvalue '=' expression
      {
        $$ = create_node("="); 
        add_child($$, $1); 
        add_child($$, $3); 
      }
    ;

lvalue:
      IDENTIFIER
        { $$ = create_node("lvalue"); }
    | IDENTIFIER '[' expression ']'
        { $$ = create_node("lvalue[]"); add_child($$, $3); }
    | IDENTIFIER '.' IDENTIFIER
        { $$ = create_node("lvalue."); }
    | IDENTIFIER PTR_OP IDENTIFIER
        { $$ = create_node("lvalue->"); }
    | '*' IDENTIFIER
        { $$ = create_node("lvalue*"); }
    ;

/* loops */

loop_stmt:
      WHILE '(' expression ')' statement
        { $$ = create_node("while"); add_child($$, $3); add_child($$, $5); }
    | DO statement WHILE '(' expression ')' ';'
        { $$ = create_node("do-while"); add_child($$, $2); add_child($$, $5); }
    | FOR '(' assignment ';' expression ';' assignment ')' statement
        { $$ = create_node("for"); add_child($$, $3); add_child($$, $5); add_child($$, $7); add_child($$, $9); }
    ;


/* switch */

switch_stmt:
      SWITCH '(' expression ')' '{' case_list '}'
        { $$ = create_node("switch"); add_child($$, $3); add_child($$, $6); }
    ;

case_list:
      case_list case_block
    | case_block
    ;

case_block:
      CASE INT_CONST ':' statement_list
        { $$ = create_node("case"); add_child($$, $4); }
    | DEFAULT ':' statement_list
        { $$ = create_node("default"); add_child($$, $3); }
    ;


/* expression list */

expression_list:
      expression_list ',' expression
    | expression
    ;

/* expression hierarchy */

expression:
      logical_or_expr {
        $$ = $1; 
      }
    ;

logical_or_expr:
      logical_or_expr OR_OP logical_and_expr
      { $$ = create_node("||"); add_child($$,$1); add_child($$,$3); }
    | logical_and_expr
    { $$ = $1; }

    ;

logical_and_expr:
      logical_and_expr AND_OP bitwise_or_expr
      { $$ = create_node("&&"); add_child($$,$1); add_child($$,$3); }
    | bitwise_or_expr
        { $$ = $1; }
    ;

bitwise_or_expr:
      bitwise_or_expr '|' bitwise_xor_expr
      { $$ = create_node("|"); add_child($$,$1); add_child($$,$3); }
    | bitwise_xor_expr
    { $$ = $1; }
    ;

bitwise_xor_expr:
      bitwise_xor_expr '^' bitwise_and_expr
      { $$ = create_node("^"); add_child($$,$1); add_child($$,$3); }
    | bitwise_and_expr
    { $$ = $1; }
    ;

bitwise_and_expr:
      bitwise_and_expr '&' equality_expr
      { $$ = create_node("&"); add_child($$,$1); add_child($$,$3); }
    | equality_expr
    { $$ = $1; }
    ;

equality_expr:
      equality_expr EQ_OP relational_expr
        { $$ = create_node("=="); add_child($$,$1); add_child($$,$3); }
    | equality_expr NE_OP relational_expr
        { $$ = create_node("!="); add_child($$,$1); add_child($$,$3); }
    | relational_expr
        { $$ = $1; }
    ;

relational_expr:
      relational_expr '<' shift_expr
        { $$ = create_node("<"); add_child($$,$1); add_child($$,$3); }
    | relational_expr '>' shift_expr
        { $$ = create_node(">"); add_child($$,$1); add_child($$,$3); }
    | relational_expr LE_OP shift_expr
        { $$ = create_node("<="); add_child($$,$1); add_child($$,$3); }
    | relational_expr GE_OP shift_expr
        { $$ = create_node(">="); add_child($$,$1); add_child($$,$3); }
    | shift_expr
        { $$ = $1; }
    ;

shift_expr:
      shift_expr SHL_OP additive_expr
        { $$ = create_node("<<"); add_child($$,$1); add_child($$,$3); }
    | shift_expr SHR_OP additive_expr
        { $$ = create_node(">>"); add_child($$,$1); add_child($$,$3); }
    | additive_expr
        { $$ = $1; }
    ;

additive_expr:
      additive_expr '+' multiplicative_expr 
      {
        $$ = create_node ("+"); 
        add_child ($$, $1); 
        add_child ($$, $3); 
      }
    | additive_expr '-' multiplicative_expr
      {
        $$ = create_node ("-"); 
        add_child ($$, $1); 
        add_child ($$, $3); 
      }
    | multiplicative_expr 
      {
        $$ = $1; 
      }
    ;

multiplicative_expr:
      multiplicative_expr '*' unary_expr 
      {
        $$ = create_node ("*"); 
        add_child ($$, $1); 
        add_child ($$, $3);
      }
    | multiplicative_expr '/' unary_expr
    | multiplicative_expr '%' unary_expr
    | unary_expr 
      {
        $$ = $1; 
      }
    ;

unary_expr:
      '-' unary_expr %prec UMINUS
        { $$ = create_node("unary-"); add_child($$, $2); }
    | '!' unary_expr
        { $$ = create_node("!"); add_child($$, $2); }
    | '~' unary_expr
        { $$ = create_node("~"); add_child($$, $2); }
    | '*' unary_expr
        { $$ = create_node("deref*"); add_child($$, $2); }
    | '&' unary_expr
        { $$ = create_node("addr&"); add_child($$, $2); }
    | postfix_expr  { $$ = $1; }
    ;

postfix_expr:
      postfix_expr INC_OP
        { $$ = create_node("++"); add_child($$, $1); }
    | postfix_expr DEC_OP
        { $$ = create_node("--"); add_child($$, $1); }
    | primary_expr  { $$ = $1; }
    ;


primary_expr:
      IDENTIFIER
        { $$ = create_node("id"); }
    | IDENTIFIER '(' argument_list ')'
        { $$ = create_node("call"); add_child($$, $3); }
    | IDENTIFIER '(' ')'
        { $$ = create_node("call"); }
    | IDENTIFIER '[' expression ']'
        { $$ = create_node("index"); add_child($$, $3); }
    | INT_CONST
        { $$ = create_node("int"); }
    | FLOAT_CONST
        { $$ = create_node("float"); }
    | CHAR_CONST
        { $$ = create_node("char"); }
    | STRING_LITERAL
        { $$ = create_node("string"); }
    | SIZEOF '(' expression ')'
        { $$ = create_node("sizeof"); add_child($$, $3); }
    | '(' expression ')'
        { $$ = $2; }
    ;


/* arguments */

argument_list:
      argument_list ',' expression
    | expression
    ;

%%

void yyerror(const char *s)
{
    /*if (strcmp(yytext, "") == 0 || strcmp(yytext, "$end") == 0)
        report_error(ERR_MISSING_SEMICOLON, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, ")") == 0)
        report_error(ERR_MISSING_CLOSING_PAREN, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, "}") == 0)
        report_error(ERR_MISSING_CLOSING_BRACE, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, "]") == 0)
        report_error(ERR_MISSING_CLOSING_BRACKET, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, "{") == 0)
        report_error(ERR_MISSING_OPENING_BRACE, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, "(") == 0)
        report_error(ERR_MISSING_OPENING_PAREN, yyprevline, yyprevcol, yytext);
    else if (strcmp(yytext, ";") == 0)
        report_error(ERR_MISSING_SEMICOLON, yyprevline, yyprevcol, yytext);
    else
        report_error(ERR_GENERIC, yyprevline, yyprevcol, yytext); */
    
    printf("\n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("║           PARSE ERROR                   ║\n");
    printf("╚══════════════════════════════════════════╝\n");

    if ((strcmp(yytext, "if")     == 0 ||
        strcmp(yytext, "while")  == 0 ||
        strcmp(yytext, "for")    == 0 ||
        strcmp(yytext, "do")     == 0 ||
        strcmp(yytext, "switch") == 0 ||
        strcmp(yytext, "return") == 0 ||
        strcmp(yytext, "break")  == 0 ||
        strcmp(yytext, "continue") == 0))
    {
        printf("  Location : line %d\n", yyline);
        printf("  Token    : '%s'\n", yytext);
        printf("  Error    : '%s' cannot appear at global scope\n", yytext);
        printf("  Fix      : control flow statements must be inside a func\n");
        printf("  Example  :\n");
        printf("             func main() {\n");
        printf("                 if (x > 0) { ... }\n");
        printf("             }\n");
    }
    
    
    else if (strcmp(yytext, "var")      == 0 ||
        strcmp(yytext, "func")     == 0 ||
        strcmp(yytext, "extern") == 0 ||
         strcmp(yytext, "struct") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline-1, yyprevendcol);
        printf("  Token    : '%s' (unexpected keyword)\n", yytext);
        printf("  Error    : missing ';' at end of line %d\n", yyline - 1);
        printf("  Fix      : add ';' at the end of line %d\n", yyline - 1);
    }
    else if (strcmp(yytext, "{") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : '{'\n");
        printf("  Error    : missing condition in '(' ')'\n");
        printf("  Fix      : wrap condition in parentheses\n");
        printf("  Example  : if (x > 0) { ... }\n");
    }
    else if (strcmp(yytext, ")") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : ')'\n");
        printf("  Error    : missing closing ')'\n");
        printf("  Fix      : check parentheses are balanced\n");
    }
    else if (strcmp(yytext, "(") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : '('\n");
        printf("  Error    : missing '(' after keyword\n");
        printf("  Fix      : add '(' after if/while/for/switch\n");
        printf("  Example  : if (x > 0) { ... }\n");
    }
    else if (strcmp(yytext, "}") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : '}'\n");
        printf("  Error    : unexpected '}' or unmatched brace\n");
        printf("  Fix      : check all braces are balanced\n");
    }
    else if (strcmp(yytext, ";") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : ';'\n");
        printf("  Error    : unexpected ';' — missing expression?\n");
        printf("  Fix      : check expression before ';'\n");
        printf("  Example  : var x = a + b;  <-- expression needed\n");
    }
    else if (strcmp(yytext, "+") == 0 ||
             strcmp(yytext, "-") == 0 ||
             strcmp(yytext, "*") == 0 ||
             strcmp(yytext, "/") == 0 ||
             strcmp(yytext, "%") == 0)
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : '%s'\n", yytext);
        printf("  Error    : unexpected operator '%s' — missing operand?\n", yytext);
        printf("  Fix      : check both sides of operator have values\n");
        printf("  Example  : var x = a + b;  <-- both operands needed\n");
    }
    else if (strcmp(yytext, "") == 0)
    {
        printf("  Location : line %d\n", yyline);
        printf("  Token    : end of file\n");
        printf("  Error    : unexpected end of file\n");
        printf("  Fix      : check last statement ends with ';'\n");
        printf("           : check all blocks closed with '}'\n");
    }
    else
    {
        printf("  Location : line %d, column %d\n", yyline, yycol);
        printf("  Token    : '%s'\n", yytext);
        printf("  Error    : unexpected token '%s'\n", yytext);
        printf("  Fix      : check syntax around this location\n");
    }

    printf("══════════════════════════════════════════════\n\n"); 

}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
        return 0;
    }


    yyin = fopen(argv[1], "r");

    if(!yyin)
    {
        printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
        return 0;
    }

    char outname[256];
    strcpy(outname, argv[1]);

    char *dot = strrchr(outname, '.');
    if(dot) *dot = '\0';
    strcat(outname, "_output.lang");

    yyout = fopen(outname, "w");

    if(yyparse()==0)
    {
        printf("\nParsing Successful\n\nReverse Derivation Tree:\n");
        print_reverse_tree(root);
    }



    fclose(yyin);
    fclose(yyout);

    return 0;
}