//
// Created by mingtao on 10/26/16.
//

#include "Math.h"

Math::Math(Token * token, Expr * expr1, Expr * expr2): Expr(token) {
    this->expr_l = expr1;
    this->expr_r = expr2;
    lexline = token->line;
}
