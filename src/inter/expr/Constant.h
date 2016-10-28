//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H


#include "Expr.h"

class Constant: public Expr{

public:
    Constant(Token *);
    int value;

    int execute();
};


#endif //COMPILER_CONSTANT_H
