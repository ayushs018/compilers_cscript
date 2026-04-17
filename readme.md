# CScript Compiler – Intermediate Code Generation using Lex & Yacc
 
## Overview
 
This project implements a compiler front-end for a small C-like language (**CScript**) using **Lex and Yacc**.
 
The compiler performs:
 
1. Lexical Analysis
2. Syntax Analysis
3. Abstract Syntax Tree (AST) generation
4. Intermediate Code Generation (Three Address Code – TAC)
5. Error Handling
The intermediate representation (IR) is generated using **Syntax Directed Translation (SDT)** and stored in **Quadruple format**.
 
---
 
## Project Structure
 
```
CScript/
│
├── tests_ir_code_gen/
│   ├── t1.cs
│   ├── t1_output.lang
│   ├── t1_tac.txt
│   ├── t2.cs
│   ├── t2_output.lang
│   ├── t2_tac.txt
│   ├── t3.cs
│   ├── t3_output.lang
│   ├── t3_tac.txt
│   ├── t4.cs
│   ├── t4_output.lang
│   └── t4_tac.txt
│
├── lexer.l
├── parser.y
├── ast.c
├── ast.h
├── ir.c
├── ir.h
├── errors.c
├── errors.h
├── gen_table.c
├── print_table.c
├── parsing_table.txt
├── Makefile
├── readme.md
│
├── lex.yy.c
├── y.tab.c
├── y.tab.h
├── y.output
└── a.out
```
 
---
 
## Compiler Pipeline
 
```
Source Code (.cs)
       ↓
Lexical Analysis (lexer.l)
       ↓
     Tokens
       ↓
Syntax Analysis (parser.y)
       ↓
Abstract Syntax Tree (AST)
       ↓
Intermediate Code Generation (ir.c)
       ↓
Three Address Code (TAC)
       ↓
  Output File (_tac.txt)
```
 
---
 
## Setup Instructions
 
### Install Dependencies (Ubuntu / WSL)
 
```bash
sudo apt update
sudo apt install flex
sudo apt install bison
sudo apt install build-essential
```
 
Verify installation:
 
```bash
flex --version
bison --version
gcc --version
```
 
---
 
## Build Instructions
 
Navigate to project directory:
 
```bash
cd CScript
```
 
Compile:
 
```bash
make
```
 
Generated files:
 
```
a.out
lex.yy.c
y.tab.c
```
 
---
 
## Run the Compiler
 
Run the compiler on an input file:
 
```bash
./a.out tests_ir_code_gen/t1.cs
```
 
Example:
 
```bash
./a.out tests_ir_code_gen/t3.cs
```
 
---
 
## Output Files
 
For input file `t1.cs`, the compiler generates:
 
```
t1_output.lang   → lexical tokens
t1_tac.txt       → three address code
```
 
---
 
## Intermediate Representation (TAC)
 
Three Address Code uses **quadruple format**:
 
| op  | arg1 | arg2 | result |
|-----|------|------|--------|
| +   | b    | c    | t0     |
| *   | a    | t0   | t1     |
| =   | t1   | -    | x      |
 
Meaning:
 
```
t0 = b + c
t1 = a * t0
x  = t1
```
 
---
 
## Supported Constructs
 
### Arithmetic Expression
 
Source:
```c
a = b*c + b*c;
```
 
TAC:
```
* b c t0
* b c t1
+ t0 t1 t2
= t2 - a
```
 
---
 
### Assignment Statement
 
Source:
```c
a = b + c;
```
 
TAC:
```
+ b c t0
= t0 - a
```
 
---
 
### If Statement
 
Source:
```c
if(a)
{
    b = 1;
}
```
 
TAC:
```
IF_FALSE a L0
= 1 - b
LABEL L0
```
 
---
 
### If-Else Statement
 
Source:
```c
if(a)
    b = 1;
else
    b = 2;
```
 
TAC:
```
IF_FALSE a L0
= 1 - b
GOTO L1
LABEL L0
= 2 - b
LABEL L1
```
 
---
 
### While Loop
 
Source:
```c
while(b > 0)
{
    b = b - 1;
}
```
 
TAC:
```
LABEL L0
> b 0 t0
IF_FALSE t0 L1
- b 1 t1
= t1 - b
GOTO L0
LABEL L1
```
 
---
 
### For Loop
 
Source:
```c
for(i=0; i<5; i=i+1)
{
    sum = sum + i;
}
```
 
TAC:
```
= 0 - i
 
LABEL L0
< i 5 t0
IF_FALSE t0 L1
 
+ sum i t1
= t1 - sum
 
+ i 1 t2
= t2 - i
 
GOTO L0
LABEL L1
```
 
---
 
## Temporary Variables
 
Temporary variables store intermediate values: `t0, t1, t2, t3...`
 
Example:
```c
a = b + c*d
```
 
TAC:
```
* c d t0
+ b t0 t1
= t1 - a
```
 
---
 
## Labels in TAC
 
Labels represent positions in code:
 
```
LABEL L0
GOTO L0
```
 
Used for:
- Loops
- If statements
- Conditional jumps
---
 
## Error Handling
 
The compiler detects syntax errors such as:
 
### Missing Semicolon
 
```c
var a
```
 
Error:
```
missing ';'
```
 
### Invalid Expression
 
```c
a = b + ;
```
 
Error:
```
missing operand
```
 
### Unmatched Brackets
 
```c
if(a>0
{
    b=1;
}
```
 
Error:
```
missing closing parenthesis
```
 
---
 
## Clean Build
 
Remove generated files:
 
```bash
make clean
```
