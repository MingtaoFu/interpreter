//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H


#include "../Stmt.h"
#include "../../../lexer/Token.h"

class Expr: public Stmt{
public:
    Token * op;
    Expr(Token *);

    virtual int execute();
};


#endif //COMPILER_EXPR_H
