#include "ast.h"

static const char *terminals[] = {
    "VAR", "FUNC", "EXTERN", "STRUCT",
    "IF", "ELSE", "FOR", "WHILE", "DO",
    "SWITCH", "CASE", "DEFAULT",
    "BREAK", "CONTINUE", "RETURN", "SIZEOF",
    "IDENTIFIER", "INT_CONST", "FLOAT_CONST",
    "CHAR_CONST", "STRING_LITERAL",
    "INC_OP", "DEC_OP", "PTR_OP",
    "AND_OP", "OR_OP",
    "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
    "SHL_OP", "SHR_OP",
    "+", "-", "*", "/", "%",
    "<", ">", "&", "|", "^",
    "!", "~", "=",
    "(", ")", "[", "]", "{", "}", ",", ";", ".",
    "$end",
    NULL
};

static const char *nonterminals[] = {
    "program", "global_list", "global",
    "var_decl", "var_init_list", "var_init",
    "func_decl", "param_list", "param",
    "block", "statement_list", "statement",
    "assignment", "lvalue",
    "expression", "logical_or_expr", "logical_and_expr",
    "bitwise_or_expr", "bitwise_xor_expr", "bitwise_and_expr",
    "equality_expr", "relational_expr", "shift_expr",
    "additive_expr", "multiplicative_expr",
    "unary_expr", "postfix_expr", "primary_expr",
    "argument_list", "expression_list",
    "loop_stmt", "switch_stmt",
    "case_list", "case_block",
    "extern_decl", "struct_decl", "var_decl_list",
    NULL
};

typedef struct {
    char action[96];
} Cell;

#define MAX_STATES  250
#define MAX_SYMBOLS 100

static Cell action_table[MAX_STATES][MAX_SYMBOLS];
static Cell goto_table  [MAX_STATES][MAX_SYMBOLS];
static int  max_state = 0;

static int term_index(const char *sym)
{
    for (int i = 0; terminals[i]; i++)
        if (strcmp(terminals[i], sym) == 0) return i;
    return -1;
}

static int nonterm_index(const char *sym)
{
    for (int i = 0; nonterminals[i]; i++)
        if (strcmp(nonterminals[i], sym) == 0) return i;
    return -1;
}

static void load_table()
{
    FILE *f = fopen("y.output", "r");
    if (!f)
    {
        printf("ERROR: y.output not found.\n");
        return;
    }

    memset(action_table, 0, sizeof(action_table));
    memset(goto_table,   0, sizeof(goto_table));

    char line[1024];
    int  state_num = -1;
    int  in_state  = 0;

    while (fgets(line, sizeof(line), f))
    {
        if (strncmp(line, "State ", 6) == 0)
        {
            int n;
            if (sscanf(line, "State %d", &n) == 1)
            {
                state_num = n;
                in_state  = 1;
                if (n > max_state) max_state = n;
            }
            continue;
        }

        if (!in_state || line[0] == '\n') continue;

        char *p = line;
        while (*p == ' ') p++;

        /* SHIFT */
        if (strstr(line, "shift, and go to state"))
        {
            char symbol[64] = "";
            int  target     = -1;

            char *sym_end = strstr(p, "shift");
            if (sym_end)
            {
                int len = (int)(sym_end - p);
                while (len > 0 && p[len-1] == ' ') len--;
                if (len > 63) len = 63;
                strncpy(symbol, p, len);
                symbol[len] = '\0';
            }

            char *st = strstr(line, "go to state");
            if (st) sscanf(st + 11, "%d", &target);

            int idx = term_index(symbol);
            if (idx >= 0 && target >= 0 && state_num >= 0)
                snprintf(action_table[state_num][idx].action, 96, "s%d", target);
        }

        /* GOTO */
        else if (strstr(line, "go to state") && !strstr(line, "shift"))
        {
            char symbol[64] = "";
            int  target     = -1;

            char *go = strstr(p, "go to state");
            if (go)
            {
                int len = (int)(go - p);
                while (len > 0 && p[len-1] == ' ') len--;
                if (len > 63) len = 63;
                strncpy(symbol, p, len);
                symbol[len] = '\0';
                sscanf(go + 11, "%d", &target);
            }

            int idx = nonterm_index(symbol);
            if (idx >= 0 && target >= 0 && state_num >= 0)
                snprintf(goto_table[state_num][idx].action, 96, "%d", target);
        }

        /* REDUCE */
        else if (strstr(line, "reduce using rule"))
        {
            char symbol[64] = "$default";
            int  rule       = -1;

            if (strncmp(p, "reduce",   6) != 0 &&
                strncmp(p, "$default", 8) != 0)
            {
                char *r = strstr(p, "reduce");
                if (r)
                {
                    int len = (int)(r - p);
                    while (len > 0 && p[len-1] == ' ') len--;
                    if (len > 63) len = 63;
                    strncpy(symbol, p, len);
                    symbol[len] = '\0';
                }
            }

            char *rul = strstr(line, "rule");
            if (rul) sscanf(rul + 4, "%d", &rule);

            if (rule < 0) continue;

            char rulename[64] = "";
            char *lp = strstr(line, "(");
            char *rp = strstr(line, ")");
            if (lp && rp && rp > lp)
            {
                int len = (int)(rp - lp - 1);
                if (len > 63) len = 63;
                strncpy(rulename, lp + 1, len);
                rulename[len] = '\0';
            }

            char cell[96];
            if (rulename[0])
                snprintf(cell, 96, "r%d(%s)", rule, rulename);
            else
                snprintf(cell, 96, "r%d", rule);

            if (strcmp(symbol, "$default") == 0)
            {
                for (int i = 0; terminals[i]; i++)
                    if (action_table[state_num][i].action[0] == '\0')
                        strncpy(action_table[state_num][i].action, cell, 95);
            }
            else
            {
                int idx = term_index(symbol);
                if (idx >= 0)
                    strncpy(action_table[state_num][idx].action, cell, 95);
            }
        }

        /* ACCEPT */
        else if (strstr(line, "accept"))
        {
            int idx = term_index("$end");
            if (idx >= 0)
                strncpy(action_table[state_num][idx].action, "acc", 95);
        }
    }

    fclose(f);
}

void print_parsing_table()
{
    load_table();

    /* open output file */
    FILE *out = fopen("parsing_table.txt", "w");
    if (!out)
    {
        printf("ERROR: Cannot create parsing_table.txt\n");
        return;
    }

    int num_terms    = 0;
    int num_nonterms = 0;
    while (terminals   [num_terms])    num_terms++;
    while (nonterminals[num_nonterms]) num_nonterms++;

    int cw = 14;

    /* banner */
    fprintf(out, "\n");
    fprintf(out, "==========================================================\n");
    fprintf(out, "                 LALR(1) PARSING TABLE                   \n");
    fprintf(out, "==========================================================\n\n");

    /* ACTION TABLE */
    fprintf(out, "--- ACTION TABLE (terminals) ---\n\n");

    fprintf(out, "%-6s", "State");
    for (int j = 0; j < num_terms; j++)
        fprintf(out, "| %-*s", cw, terminals[j]);
    fprintf(out, "|\n");

    fprintf(out, "------");
    for (int j = 0; j < num_terms; j++)
    {
        fprintf(out, "+");
        for (int k = 0; k < cw + 1; k++) fprintf(out, "-");
    }
    fprintf(out, "+\n");

    for (int i = 0; i <= max_state; i++)
    {
        int has_entry = 0;
        for (int j = 0; j < num_terms; j++)
            if (action_table[i][j].action[0]) { has_entry = 1; break; }
        if (!has_entry) continue;

        fprintf(out, "%-6d", i);
        for (int j = 0; j < num_terms; j++)
            fprintf(out, "| %-*s", cw, action_table[i][j].action);
        fprintf(out, "|\n");
    }

    fprintf(out, "------");
    for (int j = 0; j < num_terms; j++)
    {
        fprintf(out, "+");
        for (int k = 0; k < cw + 1; k++) fprintf(out, "-");
    }
    fprintf(out, "+\n");

    /* GOTO TABLE */
    fprintf(out, "\n--- GOTO TABLE (non-terminals) ---\n\n");

    fprintf(out, "%-6s", "State");
    for (int j = 0; j < num_nonterms; j++)
        fprintf(out, "| %-*s", cw, nonterminals[j]);
    fprintf(out, "|\n");

    fprintf(out, "------");
    for (int j = 0; j < num_nonterms; j++)
    {
        fprintf(out, "+");
        for (int k = 0; k < cw + 1; k++) fprintf(out, "-");
    }
    fprintf(out, "+\n");

    for (int i = 0; i <= max_state; i++)
    {
        int has_entry = 0;
        for (int j = 0; j < num_nonterms; j++)
            if (goto_table[i][j].action[0]) { has_entry = 1; break; }
        if (!has_entry) continue;

        fprintf(out, "%-6d", i);
        for (int j = 0; j < num_nonterms; j++)
            fprintf(out, "| %-*s", cw, goto_table[i][j].action);
        fprintf(out, "|\n");
    }

    fprintf(out, "------");
    for (int j = 0; j < num_nonterms; j++)
    {
        fprintf(out, "+");
        for (int k = 0; k < cw + 1; k++) fprintf(out, "-");
    }
    fprintf(out, "+\n");

    fprintf(out, "\nKey:\n");
    fprintf(out, "  sN       = shift, go to state N\n");
    fprintf(out, "  rN(rule) = reduce by rule N\n");
    fprintf(out, "  N        = goto state N (GOTO table)\n");
    fprintf(out, "  acc      = accept\n");
    fprintf(out, "  (blank)  = error\n\n");

    fclose(out);

    /* tell user where the file is */
    printf("\nParsing table written to: parsing_table.txt\n");
}