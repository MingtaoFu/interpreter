//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_SET_H
#define COMPILER_SET_H


#include "Stmt.h"
#include "../expr/Expr.h"
#include "../expr/Id.h"

class Set: public Stmt {
public:
    Id * id;
    Expr * expr;
    Set(Id *, Expr *);
    void execute();
};


#endif //COMPILER_SET_H
