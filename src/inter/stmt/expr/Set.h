//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_SET_H
#define COMPILER_SET_H


#include "../Stmt.h"
#include "../expr/Expr.h"
#include "../expr/Id.h"
#include "../expr/Var.h"
#include "Math.h"

class Set: public Math {
public:
    Set(Token *, Var *, Expr *);
    int execute();
};


#endif //COMPILER_SET_H
