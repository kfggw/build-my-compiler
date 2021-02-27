#include <stdlib.h>
#include <string.h>
#include "create.h"

const int kExprSize = sizeof(Expression);
const int kStmtSize = sizeof(Statement);
const int kStmtListSize = sizeof(StatementList);

StatementList *gStmtList = NULL;

Expression *CreateNumberExpr(double number) {
  Expression *expr = malloc(kExprSize);
  expr->number = number;
  expr->type = Number_Expr;
  
  return expr;
}

Expression *CreateIdExpr(char *id) {
  char *id_name = malloc(strlen(id));
  memcpy(id_name, id, strlen(id));

  Expression *expr = malloc(kExprSize);
  expr->identifier = id;
  expr->type = ID_Expr;

  return expr;
}

Expression *CreateBinExpr(enum ExprType bin_type, Expression *left, Expression *right) {
  Expression *expr = malloc(kExprSize);
  expr->type = bin_type;
  expr->left = left;
  expr->right = right;

  return expr;
}


Statement *CreateAssignStmt(char *id, Expression *expr) {
  Statement *stmt = malloc(kStmtSize);
  stmt->type = Assign_Stmt;

  stmt->identifier = id;
  stmt->expr = expr;
  
  return stmt;
}

Statement *CreatePrintStmt(Expression *expr) {
  Statement *stmt = malloc(kStmtSize);
  stmt->type = Print_Stmt;
  stmt->expr = expr;

  return stmt;
}

void CreateStmtList(Statement *stmt) {
  gStmtList = malloc(kStmtListSize);
  gStmtList->stmt = stmt;
  gStmtList->next = 0;
}

void ChainStmtToList(Statement *stmt) {
  StatementList *stmt_list = malloc(kStmtListSize);
  stmt_list->stmt = stmt;
  stmt_list->next = 0;
  
  StatementList *cur_list = gStmtList;
  while(cur_list->next) {
    cur_list = cur_list->next;
  }
  
  cur_list->next = stmt_list;
}

char *CopyStr(const char *origin, int len) {
  char *copy = malloc(len+1);
  memcpy(copy, origin, len);
  copy[len] = '\0';
  return copy;
}
