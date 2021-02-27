#include <stdio.h>
#include "create.h"
#include "evaluate.h"

extern int yyparse();
extern StatementList *gStmtList;
extern FILE* yyin;

int main(int argc, char **argv) {
  char *file_name = argv[1];

  FILE* stream = fopen(file_name, "r");
  yyin = stream;

  yyparse();
  StatementList *stmt_list = gStmtList;
  while(stmt_list) {
    ExecPrintStmt(stmt_list->stmt);
    stmt_list = stmt_list->next;
  }
  return 0;
}
