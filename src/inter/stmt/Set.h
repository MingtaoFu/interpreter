//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_SET_H
#define COMPILER_SET_H


#include "Stmt.h"
#include "../expr/Expr.h"
#include "../expr/Id.h"
#include "../expr/Var.h"

class Set: public Stmt {
public:
    Var * var;
    Expr * expr;
    Set(Var *, Expr *);
    void execute();
};


#endif //COMPILER_SET_H
