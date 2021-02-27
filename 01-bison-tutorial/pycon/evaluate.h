#ifndef EVALUATE_H_
#define EVALUATE_H_

#include "create.h"

// Expression
double EvalExpression(Expression *expr);

double EvalNumberExpr(Expression *expr);

double EvalAddExpr(Expression *expr);

double EvalSubExpr(Expression *expr);

double EvalMultiExpr(Expression *expr);

double EvalDivExpr(Expression *expr);


// Statement
void ExecAssignStmt(Statement *stmt);

void ExecPrintStmt(Statement *stmt);

#endif
