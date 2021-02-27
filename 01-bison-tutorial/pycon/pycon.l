%{

#include <stdio.h>
#include <stdlib.h>
#include "pycon.tab.h"
#include "create.h"

int yywrap();

int gLineNumber = 0;

%}

number [0-9]+\.?[0-9]*

identifier [a-zA-Z_][a-zA-Z0-9]*


%%

{number} {yylval.number = atof(yytext); return NUMBER;}

"if" {return IF;}

"elif" {return ELIF;}

"else" {return ELSE;}

"for" {return FOR;}

"while" {return WHILE;}

"def" {return DEF;}

"print" {return PRINT;}

{identifier} {yylval.id = CopyStr(yytext, yyleng); return ID;}

[\(\)\{\};\+\-\*/=] {return yytext[0];}

\n {++gLineNumber;}

. {;}

%%

int yywrap() {return 1;}
