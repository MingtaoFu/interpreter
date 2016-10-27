//
// Created by mingtao on 10/25/16.
//

#include "Expr.h"

Expr::Expr(Token * token) {
    op = token;
}

Expr::Expr(Token * token, Expr * expr1, Expr * term1) {
    op = token;
    expr = expr1;
    term = term1;
    isArith = true;
}