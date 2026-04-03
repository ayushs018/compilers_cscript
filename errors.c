#include "ast.h"
#include "errors.h"

void report_error(ErrorType type, int line, int col, const char *token)
{
    printf("\n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("║           PARSE ERROR                   ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf("  Location : line %d, column %d\n", line, col);
    printf("  Token    : '%s'\n", token ? token : "unknown");

    switch (type)
    {
        case ERR_MISSING_SEMICOLON:
            printf("  Error    : missing ';' at end of statement\n");
            printf("  Fix      : add ';' after the statement\n");
            printf("  Example  : var x = 5;  <-- semicolon required\n");
            break;

        case ERR_MISSING_CLOSING_PAREN:
            printf("  Error    : missing closing ')'\n");
            printf("  Fix      : check your parentheses are balanced\n");
            printf("  Example  : if (x > 0)  <-- closing ) required\n");
            break;

        case ERR_MISSING_CLOSING_BRACE:
            printf("  Error    : missing closing '}'\n");
            printf("  Fix      : check your braces are balanced\n");
            printf("  Example  : func f() { ... }  <-- closing } required\n");
            break;

        case ERR_MISSING_CLOSING_BRACKET:
            printf("  Error    : missing closing ']'\n");
            printf("  Fix      : check your brackets are balanced\n");
            printf("  Example  : var a[10]  <-- closing ] required\n");
            break;

        case ERR_MISSING_OPENING_BRACE:
            printf("  Error    : missing opening '{'\n");
            printf("  Fix      : function/block body must start with '{'\n");
            printf("  Example  : func f() { ... }\n");
            break;

        case ERR_UNEXPECTED_TOKEN:
            printf("  Error    : unexpected token '%s'\n", token ? token : "?");
            printf("  Fix      : remove or replace this token\n");
            break;

        case ERR_UNDECLARED:
            printf("  Error    : '%s' used but not declared\n", token ? token : "?");
            printf("  Fix      : declare with 'var %s;' before use\n", token ? token : "x");
            break;

        case ERR_MISSING_IDENTIFIER:
            printf("  Error    : expected identifier but got '%s'\n", token ? token : "?");
            printf("  Fix      : provide a valid name\n");
            printf("  Example  : var x = 5;  <-- identifier required\n");
            break;

        case ERR_MISSING_OPENING_PAREN:
            printf("  Error    : missing opening '('\n");
            printf("  Fix      : add '(' after keyword\n");
            printf("  Example  : if (x > 0)  <-- opening ( required\n");
            break;

        case ERR_MISSING_FUNC_NAME:
            printf("  Error    : missing function name after 'func'\n");
            printf("  Fix      : provide a function name\n");
            printf("  Example  : func myFunc() { ... }\n");
            break;

        case ERR_MISSING_PARAM_VAR:
            printf("  Error    : parameter must be declared with 'var'\n");
            printf("  Fix      : use 'var' before parameter name\n");
            printf("  Example  : func f(var x, var y) { ... }\n");
            break;

        case ERR_MISSING_CONDITION:
            printf("  Error    : missing condition expression\n");
            printf("  Fix      : provide a condition inside parentheses\n");
            printf("  Example  : while (x > 0) { ... }\n");
            break;

        case ERR_INCOMPLETE_EXPRESSION:
            printf("  Error    : incomplete expression near '%s'\n", token ? token : "?");
            printf("  Fix      : complete the expression\n");
            printf("  Example  : var x = a + b;  <-- full expression required\n");
            break;

        case ERR_GENERIC:
        default:
            printf("  Error    : syntax error near '%s'\n", token ? token : "unknown");
            printf("  Fix      : check syntax around this location\n");
            break;
    }

    printf("══════════════════════════════════════════════\n\n");
}