/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 91 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_FUNC = 4,                       /* FUNC  */
  YYSYMBOL_EXTERN = 5,                     /* EXTERN  */
  YYSYMBOL_STRUCT = 6,                     /* STRUCT  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_SIZEOF = 18,                    /* SIZEOF  */
  YYSYMBOL_IDENTIFIER = 19,                /* IDENTIFIER  */
  YYSYMBOL_INT_CONST = 20,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 21,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 22,                /* CHAR_CONST  */
  YYSYMBOL_STRING_LITERAL = 23,            /* STRING_LITERAL  */
  YYSYMBOL_INC_OP = 24,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 25,                    /* DEC_OP  */
  YYSYMBOL_PTR_OP = 26,                    /* PTR_OP  */
  YYSYMBOL_AND_OP = 27,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 28,                     /* OR_OP  */
  YYSYMBOL_LE_OP = 29,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 30,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 31,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 32,                     /* NE_OP  */
  YYSYMBOL_SHL_OP = 33,                    /* SHL_OP  */
  YYSYMBOL_SHR_OP = 34,                    /* SHR_OP  */
  YYSYMBOL_35_ = 35,                       /* '|'  */
  YYSYMBOL_36_ = 36,                       /* '^'  */
  YYSYMBOL_37_ = 37,                       /* '&'  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_46_ = 46,                       /* '!'  */
  YYSYMBOL_47_ = 47,                       /* '~'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_IFX = 49,                       /* IFX  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '.'  */
  YYSYMBOL_59_ = 59,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_global_list = 62,               /* global_list  */
  YYSYMBOL_global = 63,                    /* global  */
  YYSYMBOL_extern_decl = 64,               /* extern_decl  */
  YYSYMBOL_struct_decl = 65,               /* struct_decl  */
  YYSYMBOL_var_decl_list = 66,             /* var_decl_list  */
  YYSYMBOL_var_decl = 67,                  /* var_decl  */
  YYSYMBOL_var_init_list = 68,             /* var_init_list  */
  YYSYMBOL_var_init = 69,                  /* var_init  */
  YYSYMBOL_func_decl = 70,                 /* func_decl  */
  YYSYMBOL_param_list = 71,                /* param_list  */
  YYSYMBOL_param = 72,                     /* param  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_statement_list = 74,            /* statement_list  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_assignment = 76,                /* assignment  */
  YYSYMBOL_lvalue = 77,                    /* lvalue  */
  YYSYMBOL_loop_stmt = 78,                 /* loop_stmt  */
  YYSYMBOL_switch_stmt = 79,               /* switch_stmt  */
  YYSYMBOL_case_list = 80,                 /* case_list  */
  YYSYMBOL_case_block = 81,                /* case_block  */
  YYSYMBOL_expression_list = 82,           /* expression_list  */
  YYSYMBOL_expression = 83,                /* expression  */
  YYSYMBOL_logical_or_expr = 84,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 85,          /* logical_and_expr  */
  YYSYMBOL_bitwise_or_expr = 86,           /* bitwise_or_expr  */
  YYSYMBOL_bitwise_xor_expr = 87,          /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 88,          /* bitwise_and_expr  */
  YYSYMBOL_equality_expr = 89,             /* equality_expr  */
  YYSYMBOL_relational_expr = 90,           /* relational_expr  */
  YYSYMBOL_shift_expr = 91,                /* shift_expr  */
  YYSYMBOL_additive_expr = 92,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 93,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 94,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 95,              /* postfix_expr  */
  YYSYMBOL_primary_expr = 96,              /* primary_expr  */
  YYSYMBOL_argument_list = 97              /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    44,    37,     2,
      56,    57,    42,    40,    53,    41,    58,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    50,
      38,    48,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    35,    52,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      45,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    81,    88,    94,    95,    96,    97,   104,
     108,   112,   113,   117,   125,   126,   130,   132,   134,   136,
     144,   146,   151,   152,   156,   163,   169,   171,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   188,   190,   192,
     193,   200,   209,   211,   213,   215,   217,   224,   226,   228,
     236,   241,   242,   246,   248,   256,   257,   263,   269,   271,
     277,   279,   284,   286,   291,   293,   298,   300,   305,   307,
     309,   314,   316,   318,   320,   322,   327,   329,   331,   336,
     342,   348,   355,   361,   362,   363,   370,   372,   374,   376,
     378,   380,   384,   386,   388,   393,   395,   397,   399,   401,
     403,   405,   407,   409,   411,   419,   420
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "FUNC",
  "EXTERN", "STRUCT", "IF", "ELSE", "FOR", "WHILE", "DO", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "CONTINUE", "RETURN", "SIZEOF", "IDENTIFIER",
  "INT_CONST", "FLOAT_CONST", "CHAR_CONST", "STRING_LITERAL", "INC_OP",
  "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "SHL_OP", "SHR_OP", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'='", "IFX", "';'",
  "'{'", "'}'", "','", "'['", "']'", "'('", "')'", "'.'", "':'", "$accept",
  "program", "global_list", "global", "extern_decl", "struct_decl",
  "var_decl_list", "var_decl", "var_init_list", "var_init", "func_decl",
  "param_list", "param", "block", "statement_list", "statement",
  "assignment", "lvalue", "loop_stmt", "switch_stmt", "case_list",
  "case_block", "expression_list", "expression", "logical_or_expr",
  "logical_and_expr", "bitwise_or_expr", "bitwise_xor_expr",
  "bitwise_and_expr", "equality_expr", "relational_expr", "shift_expr",
  "additive_expr", "multiplicative_expr", "unary_expr", "postfix_expr",
  "primary_expr", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,    27,    33,    24,    42,    89,    68,  -179,  -179,  -179,
    -179,  -179,   -25,    -2,  -179,   -18,    60,    46,  -179,  -179,
     308,    81,  -179,    27,     5,    49,   103,    54,   -40,  -179,
    -179,  -179,  -179,   308,   308,   308,   308,   308,   308,  -179,
     100,   105,    95,    97,    98,    37,    -8,    50,    45,    21,
    -179,    63,  -179,    82,  -179,   120,    91,   -29,  -179,  -179,
       8,  -179,   308,   308,   276,  -179,  -179,  -179,  -179,  -179,
      83,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,  -179,
    -179,    96,  -179,   269,  -179,   144,    91,   102,  -179,   101,
      93,  -179,  -179,   -17,  -179,   105,    95,    97,    98,    37,
      -8,    -8,    50,    50,    50,    50,    45,    45,    21,    21,
    -179,  -179,  -179,   106,    30,   107,   108,   109,   269,   114,
     111,   112,   308,    -9,   316,  -179,  -179,   217,  -179,   139,
     142,  -179,  -179,   141,  -179,  -179,  -179,  -179,  -179,   308,
    -179,   308,  -179,  -179,   308,    -7,   308,   143,   308,  -179,
    -179,   145,   135,   308,   140,   -22,  -179,  -179,  -179,   308,
    -179,  -179,    38,  -179,   136,    -1,   173,   146,   137,   147,
     148,  -179,  -179,   149,  -179,  -179,  -179,   308,   269,   308,
    -179,   308,   269,   308,   150,   151,  -179,   189,   153,   159,
    -179,   156,    79,   269,  -179,    -7,   160,   178,   155,     6,
    -179,  -179,   158,  -179,   163,   269,  -179,  -179,   269,   269,
     104,  -179,   165
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     8,     7,
       5,     6,    16,     0,    15,     0,     0,     0,     1,     3,
       0,     0,    13,     0,     0,     0,     0,     0,    95,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,    17,
      57,    59,    61,    63,    65,    67,    70,    75,    78,    81,
      85,    91,    94,     0,    14,     0,     0,     0,    23,     9,
       0,    12,     0,     0,     0,    90,    86,    89,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    18,    24,     0,    21,     0,     0,     0,    11,     0,
       0,    97,   106,     0,   104,    58,    60,    62,    64,    66,
      68,    69,    73,    74,    71,    72,    76,    77,    79,    80,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,    28,    31,     0,    27,     0,
       0,    32,    33,     0,    22,    20,    10,   103,    98,     0,
      96,     0,    39,    40,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,    95,    25,    26,    29,     0,
      30,   105,     0,    56,     0,    42,     0,     0,     0,     0,
       0,    36,    45,     0,    44,    41,    19,     0,     0,     0,
      46,     0,     0,     0,     0,    98,    55,    37,     0,     0,
      47,     0,     0,     0,    43,     0,     0,     0,     0,     0,
      52,    38,     0,    48,     0,     0,    50,    51,     0,     0,
       0,    49,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,   194,  -179,  -179,  -179,     7,  -179,   196,
    -179,  -179,   128,   -46,  -178,  -122,  -146,  -179,  -179,  -179,
    -179,    16,  -179,   -20,  -179,   170,   171,   157,   168,   169,
      18,    -3,    26,    19,   -32,  -179,  -179,  -179
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    60,   135,    13,    14,
      11,    57,    58,   136,   137,   138,   139,   140,   141,   142,
     209,   210,   172,   143,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    65,    66,    67,    68,    69,   157,    10,    55,   177,
      94,     1,   175,    10,    63,   167,    64,   162,    70,   207,
     208,    78,    79,    20,    95,   162,   -46,    16,    96,    21,
      80,    81,    63,    61,    64,   176,   149,   220,    24,   -42,
     150,   222,    99,   100,   102,   163,    12,    64,    22,   164,
     145,    23,    15,   189,   120,   121,   122,   164,   216,   212,
      97,    17,    56,    86,    87,    88,   197,    98,    76,    77,
     200,     1,     2,     3,     4,   112,   113,   114,   115,    25,
     152,   211,   153,    82,    83,    84,    85,    89,    90,    18,
     186,   187,   207,   208,   110,   111,   221,    26,   167,    59,
     167,    53,    67,   118,   119,   124,     1,     1,   116,   117,
      62,   125,   161,   126,   127,   128,   129,   -54,   -54,   130,
     131,   132,    27,   133,    29,    30,    31,    32,    71,   171,
      73,   173,    72,    74,   174,    75,   178,    91,   180,    92,
     104,    33,    93,   183,   123,    34,   134,    55,   148,   185,
      36,    37,   146,   179,   182,    93,   -54,   151,   147,   184,
      38,   159,   160,   154,   155,   156,   124,   196,     1,   198,
     158,   199,   125,   201,   126,   127,   128,   129,   -53,   -53,
     130,   131,   132,    27,   133,    29,    30,    31,    32,   168,
     169,   170,   190,   188,   192,   181,   191,   203,   214,   -43,
      19,   202,    33,   193,   195,   194,    34,   134,   204,   205,
     213,    36,    37,   206,   215,   218,    93,   -53,   124,    54,
       1,    38,   219,   144,   125,   217,   126,   127,   128,   129,
     107,     0,   130,   131,   132,    27,   133,    29,    30,    31,
      32,   105,   108,   106,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,    34,   134,
       0,     0,     0,    36,    37,     0,     0,     0,    93,   166,
     124,     0,     1,    38,     0,     0,   125,     0,   126,   127,
     128,   129,     0,     0,   130,   131,   132,    27,   133,    29,
      30,    31,    32,     0,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
      34,   134,     0,    33,     0,    36,    37,    34,    35,     0,
      93,     0,    36,    37,     0,    38,    27,    28,    29,    30,
      31,    32,    38,   101,    27,   165,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,     0,     0,     0,    34,
      35,     0,     0,    33,    36,    37,     0,    34,    35,     0,
       0,     0,    36,    37,    38,     0,     0,     0,     0,     0,
       0,     0,    38
};

static const yytype_int16 yycheck[] =
{
      20,    33,    34,    35,    36,    37,   128,     0,     3,   155,
      56,     3,    19,     6,    54,   137,    56,    26,    38,    13,
      14,    29,    30,    48,    53,    26,    48,     3,    57,    54,
      38,    39,    54,    26,    56,    42,    53,   215,    56,    48,
      57,   219,    62,    63,    64,    54,    19,    56,    50,    58,
      96,    53,    19,    54,    86,    87,    88,    58,    52,   205,
      52,    19,    57,    42,    43,    44,   188,    60,    31,    32,
     192,     3,     4,     5,     6,    78,    79,    80,    81,    19,
      50,   203,    52,    33,    34,    40,    41,    24,    25,     0,
      52,    53,    13,    14,    76,    77,   218,    51,   220,    50,
     222,    20,   134,    84,    85,     1,     3,     3,    82,    83,
      56,     7,   132,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    28,   149,
      35,   151,    27,    36,   154,    37,   156,    55,   158,    19,
      57,    37,    51,   163,    48,    41,    42,     3,    55,   169,
      46,    47,    50,    10,    19,    51,    52,    51,    57,    19,
      56,    50,    50,    56,    56,    56,     1,   187,     3,   189,
      56,   191,     7,   193,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    50,
      48,    50,    19,    57,    57,    50,    50,     8,    20,    48,
       6,    51,    37,    56,    55,    57,    41,    42,    55,    50,
      50,    46,    47,    57,    59,    57,    51,    52,     1,    23,
       3,    56,    59,    95,     7,   209,     9,    10,    11,    12,
      73,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    71,    74,    72,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,
       1,    -1,     3,    56,    -1,    -1,     7,    -1,     9,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    42,    -1,    37,    -1,    46,    47,    41,    42,    -1,
      51,    -1,    46,    47,    -1,    56,    18,    19,    20,    21,
      22,    23,    56,    57,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    -1,    -1,    37,    46,    47,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    61,    62,    63,    64,    65,
      67,    70,    19,    68,    69,    19,     3,    19,     0,    63,
      48,    54,    50,    53,    56,    19,    51,    18,    19,    20,
      21,    22,    23,    37,    41,    42,    46,    47,    56,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    20,    69,     3,    57,    71,    72,    50,
      66,    67,    56,    54,    56,    94,    94,    94,    94,    94,
      83,    28,    27,    35,    36,    37,    31,    32,    29,    30,
      38,    39,    33,    34,    40,    41,    42,    43,    44,    24,
      25,    55,    19,    51,    73,    53,    57,    52,    67,    83,
      83,    57,    83,    97,    57,    85,    86,    87,    88,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    93,    93,
      94,    94,    94,    48,     1,     7,     9,    10,    11,    12,
      15,    16,    17,    19,    42,    67,    73,    74,    75,    76,
      77,    78,    79,    83,    72,    73,    50,    57,    55,    53,
      57,    51,    50,    52,    56,    56,    56,    75,    56,    50,
      50,    83,    26,    54,    58,    19,    52,    75,    50,    48,
      50,    83,    82,    83,    83,    19,    42,    76,    83,    10,
      83,    50,    19,    83,    19,    83,    52,    53,    57,    54,
      19,    50,    57,    56,    57,    55,    83,    75,    83,    83,
      75,    83,    51,     8,    55,    50,    57,    13,    14,    80,
      81,    75,    76,    50,    20,    59,    52,    81,    57,    59,
      74,    75,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      65,    66,    66,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     4,
       6,     2,     1,     3,     3,     1,     1,     3,     4,     8,
       6,     5,     3,     1,     2,     3,     2,     1,     1,     2,
       2,     1,     1,     1,     2,     2,     3,     5,     7,     2,
       2,     3,     1,     4,     3,     3,     2,     5,     7,     9,
       7,     2,     1,     4,     3,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     1,     4,     3,     4,     1,
       1,     1,     1,     4,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_list  */
#line 74 "parser.y"
      {
        root = create_node("program");
        add_child(root,(yyvsp[0].node));
      }
#line 1480 "y.tab.c"
    break;

  case 3: /* global_list: global_list global  */
#line 82 "parser.y"
      {
        (yyval.node) = create_node("global_list");
        add_child((yyval.node), (yyvsp[-1].node)); 
        add_child((yyval.node), (yyvsp[0].node));
      }
#line 1490 "y.tab.c"
    break;

  case 4: /* global_list: global  */
#line 88 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node); 
      }
#line 1498 "y.tab.c"
    break;

  case 5: /* global: var_decl  */
#line 94 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1504 "y.tab.c"
    break;

  case 6: /* global: func_decl  */
#line 95 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1510 "y.tab.c"
    break;

  case 7: /* global: struct_decl  */
#line 96 "parser.y"
                      { (yyval.node) = create_node("struct_decl"); }
#line 1516 "y.tab.c"
    break;

  case 8: /* global: extern_decl  */
#line 97 "parser.y"
                      { (yyval.node) = create_node("extern_decl"); }
#line 1522 "y.tab.c"
    break;

  case 13: /* var_decl: VAR var_init_list ';'  */
#line 118 "parser.y"
      {
        (yyval.node) = create_node("var_decl");
        add_child((yyval.node), (yyvsp[-1].node));
      }
#line 1531 "y.tab.c"
    break;

  case 16: /* var_init: IDENTIFIER  */
#line 131 "parser.y"
        { (yyval.node) = create_node("var_init"); }
#line 1537 "y.tab.c"
    break;

  case 17: /* var_init: IDENTIFIER '=' expression  */
#line 133 "parser.y"
        { (yyval.node) = create_node("var_init="); add_child((yyval.node), (yyvsp[0].node)); }
#line 1543 "y.tab.c"
    break;

  case 18: /* var_init: IDENTIFIER '[' INT_CONST ']'  */
#line 135 "parser.y"
        { (yyval.node) = create_node("var_init[]"); }
#line 1549 "y.tab.c"
    break;

  case 19: /* var_init: IDENTIFIER '[' INT_CONST ']' '=' '{' expression_list '}'  */
#line 137 "parser.y"
        { (yyval.node) = create_node("var_init[]="); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1555 "y.tab.c"
    break;

  case 20: /* func_decl: FUNC IDENTIFIER '(' param_list ')' block  */
#line 145 "parser.y"
        { (yyval.node) = create_node("func_decl"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1561 "y.tab.c"
    break;

  case 21: /* func_decl: FUNC IDENTIFIER '(' ')' block  */
#line 147 "parser.y"
        { (yyval.node) = create_node("func_decl"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1567 "y.tab.c"
    break;

  case 24: /* param: VAR IDENTIFIER  */
#line 156 "parser.y"
                      { (yyval.node) = create_node("param"); }
#line 1573 "y.tab.c"
    break;

  case 25: /* block: '{' statement_list '}'  */
#line 164 "parser.y"
        { (yyval.node) = create_node("block"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1579 "y.tab.c"
    break;

  case 26: /* statement_list: statement_list statement  */
#line 170 "parser.y"
      { (yyval.node) = create_node("stmt_list"); add_child((yyval.node),(yyvsp[-1].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1585 "y.tab.c"
    break;

  case 27: /* statement_list: statement  */
#line 172 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1591 "y.tab.c"
    break;

  case 28: /* statement: var_decl  */
#line 178 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1597 "y.tab.c"
    break;

  case 29: /* statement: assignment ';'  */
#line 179 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1603 "y.tab.c"
    break;

  case 30: /* statement: expression ';'  */
#line 180 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1609 "y.tab.c"
    break;

  case 31: /* statement: block  */
#line 181 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1615 "y.tab.c"
    break;

  case 32: /* statement: loop_stmt  */
#line 182 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1621 "y.tab.c"
    break;

  case 33: /* statement: switch_stmt  */
#line 183 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1627 "y.tab.c"
    break;

  case 34: /* statement: BREAK ';'  */
#line 184 "parser.y"
                                { (yyval.node) = create_node("break"); }
#line 1633 "y.tab.c"
    break;

  case 35: /* statement: CONTINUE ';'  */
#line 185 "parser.y"
                                { (yyval.node) = create_node("continue"); }
#line 1639 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression ';'  */
#line 187 "parser.y"
        { (yyval.node) = create_node("return"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1645 "y.tab.c"
    break;

  case 37: /* statement: IF '(' expression ')' statement  */
#line 189 "parser.y"
        { (yyval.node) = create_node("if"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1651 "y.tab.c"
    break;

  case 38: /* statement: IF '(' expression ')' statement ELSE statement  */
#line 191 "parser.y"
        { (yyval.node) = create_node("if-else"); add_child((yyval.node), (yyvsp[-4].node)); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1657 "y.tab.c"
    break;

  case 39: /* statement: error ';'  */
#line 192 "parser.y"
                              { (yyval.node) = create_node("error"); yyerrok; yyclearin; }
#line 1663 "y.tab.c"
    break;

  case 40: /* statement: error '}'  */
#line 193 "parser.y"
                              { (yyval.node) = create_node("error"); yyerrok; yyclearin; }
#line 1669 "y.tab.c"
    break;

  case 41: /* assignment: lvalue '=' expression  */
#line 201 "parser.y"
      {
        (yyval.node) = create_node("="); 
        add_child((yyval.node), (yyvsp[-2].node)); 
        add_child((yyval.node), (yyvsp[0].node)); 
      }
#line 1679 "y.tab.c"
    break;

  case 42: /* lvalue: IDENTIFIER  */
#line 210 "parser.y"
        { (yyval.node) = create_node("lvalue"); }
#line 1685 "y.tab.c"
    break;

  case 43: /* lvalue: IDENTIFIER '[' expression ']'  */
#line 212 "parser.y"
        { (yyval.node) = create_node("lvalue[]"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1691 "y.tab.c"
    break;

  case 44: /* lvalue: IDENTIFIER '.' IDENTIFIER  */
#line 214 "parser.y"
        { (yyval.node) = create_node("lvalue."); }
#line 1697 "y.tab.c"
    break;

  case 45: /* lvalue: IDENTIFIER PTR_OP IDENTIFIER  */
#line 216 "parser.y"
        { (yyval.node) = create_node("lvalue->"); }
#line 1703 "y.tab.c"
    break;

  case 46: /* lvalue: '*' IDENTIFIER  */
#line 218 "parser.y"
        { (yyval.node) = create_node("lvalue*"); }
#line 1709 "y.tab.c"
    break;

  case 47: /* loop_stmt: WHILE '(' expression ')' statement  */
#line 225 "parser.y"
        { (yyval.node) = create_node("while"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1715 "y.tab.c"
    break;

  case 48: /* loop_stmt: DO statement WHILE '(' expression ')' ';'  */
#line 227 "parser.y"
        { (yyval.node) = create_node("do-while"); add_child((yyval.node), (yyvsp[-5].node)); add_child((yyval.node), (yyvsp[-2].node)); }
#line 1721 "y.tab.c"
    break;

  case 49: /* loop_stmt: FOR '(' assignment ';' expression ';' assignment ')' statement  */
#line 229 "parser.y"
        { (yyval.node) = create_node("for"); add_child((yyval.node), (yyvsp[-6].node)); add_child((yyval.node), (yyvsp[-4].node)); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1727 "y.tab.c"
    break;

  case 50: /* switch_stmt: SWITCH '(' expression ')' '{' case_list '}'  */
#line 237 "parser.y"
        { (yyval.node) = create_node("switch"); add_child((yyval.node), (yyvsp[-4].node)); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1733 "y.tab.c"
    break;

  case 53: /* case_block: CASE INT_CONST ':' statement_list  */
#line 247 "parser.y"
        { (yyval.node) = create_node("case"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1739 "y.tab.c"
    break;

  case 54: /* case_block: DEFAULT ':' statement_list  */
#line 249 "parser.y"
        { (yyval.node) = create_node("default"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1745 "y.tab.c"
    break;

  case 57: /* expression: logical_or_expr  */
#line 263 "parser.y"
                      {
        (yyval.node) = (yyvsp[0].node); 
      }
#line 1753 "y.tab.c"
    break;

  case 58: /* logical_or_expr: logical_or_expr OR_OP logical_and_expr  */
#line 270 "parser.y"
      { (yyval.node) = create_node("||"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1759 "y.tab.c"
    break;

  case 59: /* logical_or_expr: logical_and_expr  */
#line 272 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1765 "y.tab.c"
    break;

  case 60: /* logical_and_expr: logical_and_expr AND_OP bitwise_or_expr  */
#line 278 "parser.y"
      { (yyval.node) = create_node("&&"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1771 "y.tab.c"
    break;

  case 61: /* logical_and_expr: bitwise_or_expr  */
#line 280 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1777 "y.tab.c"
    break;

  case 62: /* bitwise_or_expr: bitwise_or_expr '|' bitwise_xor_expr  */
#line 285 "parser.y"
      { (yyval.node) = create_node("|"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1783 "y.tab.c"
    break;

  case 63: /* bitwise_or_expr: bitwise_xor_expr  */
#line 287 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1789 "y.tab.c"
    break;

  case 64: /* bitwise_xor_expr: bitwise_xor_expr '^' bitwise_and_expr  */
#line 292 "parser.y"
      { (yyval.node) = create_node("^"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1795 "y.tab.c"
    break;

  case 65: /* bitwise_xor_expr: bitwise_and_expr  */
#line 294 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1801 "y.tab.c"
    break;

  case 66: /* bitwise_and_expr: bitwise_and_expr '&' equality_expr  */
#line 299 "parser.y"
      { (yyval.node) = create_node("&"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1807 "y.tab.c"
    break;

  case 67: /* bitwise_and_expr: equality_expr  */
#line 301 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1813 "y.tab.c"
    break;

  case 68: /* equality_expr: equality_expr EQ_OP relational_expr  */
#line 306 "parser.y"
        { (yyval.node) = create_node("=="); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1819 "y.tab.c"
    break;

  case 69: /* equality_expr: equality_expr NE_OP relational_expr  */
#line 308 "parser.y"
        { (yyval.node) = create_node("!="); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1825 "y.tab.c"
    break;

  case 70: /* equality_expr: relational_expr  */
#line 310 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1831 "y.tab.c"
    break;

  case 71: /* relational_expr: relational_expr '<' shift_expr  */
#line 315 "parser.y"
        { (yyval.node) = create_node("<"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1837 "y.tab.c"
    break;

  case 72: /* relational_expr: relational_expr '>' shift_expr  */
#line 317 "parser.y"
        { (yyval.node) = create_node(">"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1843 "y.tab.c"
    break;

  case 73: /* relational_expr: relational_expr LE_OP shift_expr  */
#line 319 "parser.y"
        { (yyval.node) = create_node("<="); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1849 "y.tab.c"
    break;

  case 74: /* relational_expr: relational_expr GE_OP shift_expr  */
#line 321 "parser.y"
        { (yyval.node) = create_node(">="); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1855 "y.tab.c"
    break;

  case 75: /* relational_expr: shift_expr  */
#line 323 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1861 "y.tab.c"
    break;

  case 76: /* shift_expr: shift_expr SHL_OP additive_expr  */
#line 328 "parser.y"
        { (yyval.node) = create_node("<<"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1867 "y.tab.c"
    break;

  case 77: /* shift_expr: shift_expr SHR_OP additive_expr  */
#line 330 "parser.y"
        { (yyval.node) = create_node(">>"); add_child((yyval.node),(yyvsp[-2].node)); add_child((yyval.node),(yyvsp[0].node)); }
#line 1873 "y.tab.c"
    break;

  case 78: /* shift_expr: additive_expr  */
#line 332 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1879 "y.tab.c"
    break;

  case 79: /* additive_expr: additive_expr '+' multiplicative_expr  */
#line 337 "parser.y"
      {
        (yyval.node) = create_node ("+"); 
        add_child ((yyval.node), (yyvsp[-2].node)); 
        add_child ((yyval.node), (yyvsp[0].node)); 
      }
#line 1889 "y.tab.c"
    break;

  case 80: /* additive_expr: additive_expr '-' multiplicative_expr  */
#line 343 "parser.y"
      {
        (yyval.node) = create_node ("-"); 
        add_child ((yyval.node), (yyvsp[-2].node)); 
        add_child ((yyval.node), (yyvsp[0].node)); 
      }
#line 1899 "y.tab.c"
    break;

  case 81: /* additive_expr: multiplicative_expr  */
#line 349 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node); 
      }
#line 1907 "y.tab.c"
    break;

  case 82: /* multiplicative_expr: multiplicative_expr '*' unary_expr  */
#line 356 "parser.y"
      {
        (yyval.node) = create_node ("*"); 
        add_child ((yyval.node), (yyvsp[-2].node)); 
        add_child ((yyval.node), (yyvsp[0].node));
      }
#line 1917 "y.tab.c"
    break;

  case 85: /* multiplicative_expr: unary_expr  */
#line 364 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node); 
      }
#line 1925 "y.tab.c"
    break;

  case 86: /* unary_expr: '-' unary_expr  */
#line 371 "parser.y"
        { (yyval.node) = create_node("unary-"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1931 "y.tab.c"
    break;

  case 87: /* unary_expr: '!' unary_expr  */
#line 373 "parser.y"
        { (yyval.node) = create_node("!"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1937 "y.tab.c"
    break;

  case 88: /* unary_expr: '~' unary_expr  */
#line 375 "parser.y"
        { (yyval.node) = create_node("~"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1943 "y.tab.c"
    break;

  case 89: /* unary_expr: '*' unary_expr  */
#line 377 "parser.y"
        { (yyval.node) = create_node("deref*"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1949 "y.tab.c"
    break;

  case 90: /* unary_expr: '&' unary_expr  */
#line 379 "parser.y"
        { (yyval.node) = create_node("addr&"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1955 "y.tab.c"
    break;

  case 91: /* unary_expr: postfix_expr  */
#line 380 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1961 "y.tab.c"
    break;

  case 92: /* postfix_expr: postfix_expr INC_OP  */
#line 385 "parser.y"
        { (yyval.node) = create_node("++"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1967 "y.tab.c"
    break;

  case 93: /* postfix_expr: postfix_expr DEC_OP  */
#line 387 "parser.y"
        { (yyval.node) = create_node("--"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1973 "y.tab.c"
    break;

  case 94: /* postfix_expr: primary_expr  */
#line 388 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1979 "y.tab.c"
    break;

  case 95: /* primary_expr: IDENTIFIER  */
#line 394 "parser.y"
        { (yyval.node) = create_node("id"); }
#line 1985 "y.tab.c"
    break;

  case 96: /* primary_expr: IDENTIFIER '(' argument_list ')'  */
#line 396 "parser.y"
        { (yyval.node) = create_node("call"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1991 "y.tab.c"
    break;

  case 97: /* primary_expr: IDENTIFIER '(' ')'  */
#line 398 "parser.y"
        { (yyval.node) = create_node("call"); }
#line 1997 "y.tab.c"
    break;

  case 98: /* primary_expr: IDENTIFIER '[' expression ']'  */
#line 400 "parser.y"
        { (yyval.node) = create_node("index"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 2003 "y.tab.c"
    break;

  case 99: /* primary_expr: INT_CONST  */
#line 402 "parser.y"
        { (yyval.node) = create_node("int"); }
#line 2009 "y.tab.c"
    break;

  case 100: /* primary_expr: FLOAT_CONST  */
#line 404 "parser.y"
        { (yyval.node) = create_node("float"); }
#line 2015 "y.tab.c"
    break;

  case 101: /* primary_expr: CHAR_CONST  */
#line 406 "parser.y"
        { (yyval.node) = create_node("char"); }
#line 2021 "y.tab.c"
    break;

  case 102: /* primary_expr: STRING_LITERAL  */
#line 408 "parser.y"
        { (yyval.node) = create_node("string"); }
#line 2027 "y.tab.c"
    break;

  case 103: /* primary_expr: SIZEOF '(' expression ')'  */
#line 410 "parser.y"
        { (yyval.node) = create_node("sizeof"); add_child((yyval.node), (yyvsp[-1].node)); }
#line 2033 "y.tab.c"
    break;

  case 104: /* primary_expr: '(' expression ')'  */
#line 412 "parser.y"
        { (yyval.node) = (yyvsp[-1].node); }
#line 2039 "y.tab.c"
    break;


#line 2043 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 423 "parser.y"


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
