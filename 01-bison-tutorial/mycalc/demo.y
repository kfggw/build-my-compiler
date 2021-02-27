%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *s);

void putIntoTable(char name, double val);
double getFromTable(char name);

double gVals[52] = {0.0};

%}

%union {char name; double val;}
%token <val> NUM
%token <name> ID
%token PRINT EXIT
%token '='
%left '+' '-'
%left '*' '/'
%nterm <val> expr print


%%

input : %empty
| input line {}
;

line : '\n' {}
| assignment '\n' {}
| expr '\n' {}
| print '\n' {printf("%.2f\n", $1);}
| exit '\n' {exit(EXIT_SUCCESS);}
;

assignment : ID '=' expr {putIntoTable($1, $3);}

expr : NUM {$$ = $1;}
| '-' NUM {$$ = -$2;}
| ID {$$ = getFromTable($1);}
| expr '+' expr {$$ = $1 + $3;}
| expr '-' expr {$$ = $1 - $3;}
| expr '*' expr {$$ = $1 * $3;}
| expr '/' expr {$$ = $1 / $3;}
;

print : PRINT expr {$$ = $2;}

exit : EXIT {}


%%

void putIntoTable(char name, double val) {
  if(name >= 'a' && name <= 'z') {
    gVals[name - 'a'] = val;
  }
  else {
    gVals[name - 'A' + 26] = val;
  }
}

double getFromTable(char name) {
  if(name >= 'a' && name <= 'z') {
    return gVals[name - 'a'];
  }
  else {
    return gVals[name - 'A' + 26];
  }
}

void yyerror(char *s) {}

int main(void) {
  return yyparse();
}