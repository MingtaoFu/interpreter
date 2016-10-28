//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H


#include "../../lexer/Token.h"
#include "../Node.h"
#include "Constant.h"

class Expr: public Node{
public:
    bool isArith = false;
    Token * op;
    Expr * expr;
    Expr * term;
    Expr(Token *);
    Expr(Token *, Expr *, Expr *);

    virtual Constant * execute();
};


#endif //COMPILER_EXPR_H
