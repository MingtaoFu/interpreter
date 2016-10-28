//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_FACTOR_H
#define COMPILER_FACTOR_H


#include "Expr.h"

class Factor: public Expr {
public:
    Token * token;
    Factor(Token *);

    //Constant * execute();
};


#endif //COMPILER_FACTOR_H
