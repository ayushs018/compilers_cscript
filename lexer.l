%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"  
#include "y.tab.h"

extern char buff[2048];
extern int mode;
extern void yyerror(const char *);
extern FILE *yyout;
static void comment(void);

int yyline     = 1;
int yycol      = 1;
int yyprevline = 1;
int yyprevcol  = 1;
int yyprevendcol = 1; 
#define TRACK() do { yyprevline = yyline; yyprevcol = yycol; yycol += yyleng; } while(0)
%}

ID      [a-zA-Z_][a-zA-Z0-9_]*
INT     [0-9]+
HEX     0x[0-9a-fA-F]+
FLOAT   [0-9]+"."[0-9]+
CHAR    \'([^\'\\\n]|\\.)\'
STRING  \"([^\"\\\n]|\\.)*\"
WS      [ \t\n\r]+

%%

"/*"            { comment(); }
"//".*          { yycol = 1; }
[\n\r]+   { yyprevline = yyline; yyprevendcol = yycol-1; yyline++; yycol = 1; }

"var"       { TRACK(); fprintf(yyout,"KEYWORD(var)\n");      return VAR;      }
"func"      { TRACK(); fprintf(yyout,"KEYWORD(func)\n");     return FUNC;     }
"extern"    { TRACK(); fprintf(yyout,"KEYWORD(extern)\n");   return EXTERN;   }
"struct"    { TRACK(); fprintf(yyout,"KEYWORD(struct)\n");   return STRUCT;   }

"if"        { TRACK(); fprintf(yyout,"KEYWORD(if)\n");       return IF;       }
"else"      { TRACK(); fprintf(yyout,"KEYWORD(else)\n");     return ELSE;     }
"while"     { TRACK(); fprintf(yyout,"KEYWORD(while)\n");    return WHILE;    }
"for"       { TRACK(); fprintf(yyout,"KEYWORD(for)\n");      return FOR;      }
"do"        { TRACK(); fprintf(yyout,"KEYWORD(do)\n");       return DO;       }
"switch"    { TRACK(); fprintf(yyout,"KEYWORD(switch)\n");   return SWITCH;   }
"case"      { TRACK(); fprintf(yyout,"KEYWORD(case)\n");     return CASE;     }
"default"   { TRACK(); fprintf(yyout,"KEYWORD(default)\n");  return DEFAULT;  }

"break"     { TRACK(); fprintf(yyout,"KEYWORD(break)\n");    return BREAK;    }
"continue"  { TRACK(); fprintf(yyout,"KEYWORD(continue)\n"); return CONTINUE; }
"return"    { TRACK(); fprintf(yyout,"KEYWORD(return)\n");   return RETURN;   }
"sizeof"    { TRACK(); fprintf(yyout,"KEYWORD(sizeof)\n");   return SIZEOF;   }

{ID}    { TRACK(); fprintf(yyout,"IDENTIFIER(%s)\n",    yytext); return IDENTIFIER;    }
{HEX}   { TRACK(); fprintf(yyout,"INT_CONST(%s)\n",     yytext); return INT_CONST;     }
{FLOAT} { TRACK(); fprintf(yyout,"FLOAT_CONST(%s)\n",   yytext); return FLOAT_CONST;   }
{INT}   { TRACK(); fprintf(yyout,"INT_CONST(%s)\n",     yytext); return INT_CONST;     }
{CHAR}  { TRACK(); fprintf(yyout,"CHAR_CONST(%s)\n",    yytext); return CHAR_CONST;    }
{STRING} { TRACK(); fprintf(yyout,"STRING_LITERAL(%s)\n",yytext); return STRING_LITERAL;}

"++"    { TRACK(); fprintf(yyout,"INC_OP\n");   return INC_OP; }
"--"    { TRACK(); fprintf(yyout,"DEC_OP\n");   return DEC_OP; }
"->"    { TRACK(); fprintf(yyout,"PTR_OP\n");   return PTR_OP; }
"&&"    { TRACK(); fprintf(yyout,"AND_OP\n");   return AND_OP; }
"||"    { TRACK(); fprintf(yyout,"OR_OP\n");    return OR_OP;  }
"<="    { TRACK(); fprintf(yyout,"LE_OP\n");    return LE_OP;  }
">="    { TRACK(); fprintf(yyout,"GE_OP\n");    return GE_OP;  }
"=="    { TRACK(); fprintf(yyout,"EQ_OP\n");    return EQ_OP;  }
"!="    { TRACK(); fprintf(yyout,"NE_OP\n");    return NE_OP;  }
"<<"    { TRACK(); fprintf(yyout,"SHL_OP\n");   return SHL_OP; }
">>"    { TRACK(); fprintf(yyout,"SHR_OP\n");   return SHR_OP; }

";"     { TRACK(); fprintf(yyout,"SEMICOLON\n");  return ';'; }
","     { TRACK(); fprintf(yyout,"COMMA\n");      return ','; }
":"     { TRACK(); fprintf(yyout,"COLON\n");      return ':'; }
"="     { TRACK(); fprintf(yyout,"ASSIGN\n");     return '='; }
"("     { TRACK(); fprintf(yyout,"LPAREN\n");     return '('; }
")"     { TRACK(); fprintf(yyout,"RPAREN\n");     return ')'; }
"{"     { TRACK(); fprintf(yyout,"LBRACE\n");     return '{'; }
"}"     { TRACK(); fprintf(yyout,"RBRACE\n");     return '}'; }
"["     { TRACK(); fprintf(yyout,"LBRACKET\n");   return '['; }
"]"     { TRACK(); fprintf(yyout,"RBRACKET\n");   return ']'; }
"."     { TRACK(); fprintf(yyout,"DOT\n");        return '.'; }

"+"     { TRACK(); fprintf(yyout,"PLUS\n");       return '+'; }
"-"     { TRACK(); fprintf(yyout,"MINUS\n");      return '-'; }
"*"     { TRACK(); fprintf(yyout,"MULT\n");       return '*'; }
"/"     { TRACK(); fprintf(yyout,"DIV\n");        return '/'; }
"%"     { TRACK(); fprintf(yyout,"MOD\n");        return '%'; }
"&"     { TRACK(); fprintf(yyout,"BIT_AND\n");    return '&'; }
"|"     { TRACK(); fprintf(yyout,"BIT_OR\n");     return '|'; }
"^"     { TRACK(); fprintf(yyout,"BIT_XOR\n");    return '^'; }
"~"     { TRACK(); fprintf(yyout,"BIT_NOT\n");    return '~'; }
"!"     { TRACK(); fprintf(yyout,"LOG_NOT\n");    return '!'; }
"<"     { TRACK(); fprintf(yyout,"LT\n");         return '<'; }
">"     { TRACK(); fprintf(yyout,"GT\n");         return '>'; }


{WS}            { }

.               { 
                    yyprevline = yyline;
                    yyprevcol  = yycol;
                    printf("*** lexical error *** line %d, col %d: unknown character '%s'\n",
                        yyline, yycol, yytext);
                    yycol += yyleng;
                }

%%

int yywrap(void)
{
    return 1;
}

static void comment(void)
{
    int c;
    while ((c = input()) != 0)
    {
        if (c == '*')
        {
            while ((c = input()) == '*');
            if (c == '/') return;
            if (c == 0) break;
        }
    }
    fprintf(stderr,"***lexing terminated*** [lexer error]: ill-formed comment\n");
    fflush(stderr);
    exit(0);
}
