%{
#include <stdio.h>
#include <stdlib.h>
#include "create.h"

  int yylex();
  void yyerror(char *s);
  
%}

%union {double number; char *id; void *expr; void *stmt;}

%token <number> NUMBER
%token <id> ID
%token PRINT IF ELIF ELSE FOR WHILE DEF

%type <expr> expr
%type <stmt> statement

%left '+' '-'
%left '*' '/'

%%

statement_list:
statement {
  CreateStmtList($1);
}
| statement_list statement {
  ChainStmtToList($2);
}
;

expr:
NUMBER {
  $$ = CreateNumberExpr($1);
}
| ID {
  $$ = CreateIdExpr($1);
}
| expr '+' expr {
  $$ = CreateBinExpr(Add_Expr, $1, $3);
}
| expr '-' expr {
  $$ = CreateBinExpr(Sub_Expr, $1, $3);
}
| expr '*' expr {
  $$ = CreateBinExpr(Multi_Expr, $1, $3);
}
| expr '/' expr {
  $$ = CreateBinExpr(Div_Expr, $1, $3);
}
;

statement:
ID '=' expr ';' {
  $$ = CreateAssignStmt($1, $3);
}
| PRINT expr ';' {
  $$ = CreatePrintStmt($2);
}
;

%%

void yyerror(char *s) {}
