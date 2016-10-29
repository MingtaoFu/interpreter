//
// Created by mingtao on 10/26/16.
//

#include "Math.h"

Math::Math(Token * token, Expr * expr1, Expr * expr2): Expr(token) {
    this->expr1 = expr1;
    this->expr2 = expr2;
    lexline = token->line;
}
