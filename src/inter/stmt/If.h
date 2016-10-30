//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_IF_H
#define COMPILER_IF_H


#include "Stmt.h"
#include "expr/Expr.h"
#include <vector>

class If: public Stmt {
protected:
    Expr * equality;
    Stmt * stmt1;
    Stmt * stmt2;

public:
    int execute();

    If(Expr *, Stmt *, Stmt *);
};


#endif //COMPILER_IF_H
