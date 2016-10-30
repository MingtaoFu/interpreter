//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_MATH_H
#define COMPILER_MATH_H


#include "../../../lexer/Token.h"
#include "Expr.h"

class Math: public Expr {
public:
    Expr * expr_l, * expr_r;
    Math(Token *, Expr *, Expr *);
};


#endif //COMPILER_MATH_H
