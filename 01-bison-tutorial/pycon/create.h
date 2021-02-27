#ifndef CREATE_H_
#define CREATE_H_

enum ExprType {
  Number_Expr = 1,
  ID_Expr,
  Add_Expr,
  Sub_Expr,
  Multi_Expr,
  Div_Expr
};

enum StatementType {
  Assign_Stmt = 1,
  Print_Stmt
};

typedef struct Expression_tag {
  enum ExprType type;
  double number;
  char *identifier;
  struct Expression_tag *left;
  struct Expression_tag *right;
} Expression;

typedef struct Statement_tag {
  enum StatementType type;
  char *identifier;
  Expression *expr;
} Statement;

typedef struct StatementList_tag {
  Statement *stmt;
  struct StatementList_tag *next;
} StatementList;

Expression *CreateNumberExpr(double number);
Expression *CreateIdExpr(char *id);
Expression *CreateBinExpr(enum ExprType bin_type, Expression *left, Expression *right);

Statement *CreateAssignStmt(char *id, Expression *expr);
Statement *CreatePrintStmt(Expression *expr);

void CreateStmtList();
void ChainStmtToList(Statement *stmt);

char *CopyStr(const char *origin, int len);

#endif
