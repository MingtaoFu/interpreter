//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_UNARY_H
#define COMPILER_UNARY_H


#include "Math.h"
#include "Factor.h"
#include "../../lexer/Token.h"

class Unary: public Math {
public:
    Expr * factor;
    Unary(Token *, Expr *);

    void execute();
};


#endif //COMPILER_UNARY_H
