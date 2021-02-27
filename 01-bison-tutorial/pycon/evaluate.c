#include <stdio.h>
#include "evaluate.h"

double EvalExpression(Expression *expr) {
  switch (expr->type) {
  case Number_Expr:
    return EvalNumberExpr(expr);
  case Add_Expr:
    return EvalAddExpr(expr);
  case Sub_Expr:
    return EvalSubExpr(expr);
  case Multi_Expr:
    return EvalMultiExpr(expr);
  case Div_Expr:
    return EvalDivExpr(expr);
  default:
    return 0;
  }
}

double EvalNumberExpr(Expression *expr) {
  return expr->number;
}

double EvalAddExpr(Expression *expr) {
  double left_val = EvalExpression(expr->left);
  double right_val = EvalExpression(expr->right);

  return left_val + right_val;
}

double EvalSubExpr(Expression *expr) {
  double left_val = EvalExpression(expr->left);
  double right_val = EvalExpression(expr->right);

  return left_val - right_val;
}

double EvalMultiExpr(Expression *expr) {
  double left_val = EvalExpression(expr->left);
  double right_val = EvalExpression(expr->right);

  return left_val * right_val;
}

double EvalDivExpr(Expression *expr) {
  double left_val = EvalExpression(expr->left);
  double right_val = EvalExpression(expr->right);

  return left_val / right_val;
}



void ExecAssignStmt(Statement *stmt) {

}

void ExecPrintStmt(Statement *stmt) {
  double expr_value = EvalExpression(stmt->expr);
  printf("==> %f\n", expr_value);
}
