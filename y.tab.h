/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    FUNC = 259,                    /* FUNC  */
    EXTERN = 260,                  /* EXTERN  */
    STRUCT = 261,                  /* STRUCT  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    DO = 266,                      /* DO  */
    SWITCH = 267,                  /* SWITCH  */
    CASE = 268,                    /* CASE  */
    DEFAULT = 269,                 /* DEFAULT  */
    BREAK = 270,                   /* BREAK  */
    CONTINUE = 271,                /* CONTINUE  */
    RETURN = 272,                  /* RETURN  */
    SIZEOF = 273,                  /* SIZEOF  */
    IDENTIFIER = 274,              /* IDENTIFIER  */
    INT_CONST = 275,               /* INT_CONST  */
    FLOAT_CONST = 276,             /* FLOAT_CONST  */
    CHAR_CONST = 277,              /* CHAR_CONST  */
    STRING_LITERAL = 278,          /* STRING_LITERAL  */
    INC_OP = 279,                  /* INC_OP  */
    DEC_OP = 280,                  /* DEC_OP  */
    PTR_OP = 281,                  /* PTR_OP  */
    AND_OP = 282,                  /* AND_OP  */
    OR_OP = 283,                   /* OR_OP  */
    LE_OP = 284,                   /* LE_OP  */
    GE_OP = 285,                   /* GE_OP  */
    EQ_OP = 286,                   /* EQ_OP  */
    NE_OP = 287,                   /* NE_OP  */
    SHL_OP = 288,                  /* SHL_OP  */
    SHR_OP = 289,                  /* SHR_OP  */
    UMINUS = 290,                  /* UMINUS  */
    IFX = 291                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VAR 258
#define FUNC 259
#define EXTERN 260
#define STRUCT 261
#define IF 262
#define ELSE 263
#define FOR 264
#define WHILE 265
#define DO 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define BREAK 270
#define CONTINUE 271
#define RETURN 272
#define SIZEOF 273
#define IDENTIFIER 274
#define INT_CONST 275
#define FLOAT_CONST 276
#define CHAR_CONST 277
#define STRING_LITERAL 278
#define INC_OP 279
#define DEC_OP 280
#define PTR_OP 281
#define AND_OP 282
#define OR_OP 283
#define LE_OP 284
#define GE_OP 285
#define EQ_OP 286
#define NE_OP 287
#define SHL_OP 288
#define SHR_OP 289
#define UMINUS 290
#define IFX 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "parser.y"

    Node* node;

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
