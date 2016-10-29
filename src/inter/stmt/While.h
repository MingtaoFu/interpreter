//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_WHILE_H
#define COMPILER_WHILE_H

#include "Stmt.h"
#include "../expr/Expr.h"
#include "Block.h"
#include <iostream>

class While: public Stmt {
public:
    Expr* equality;
    Stmt* stmt;
    Stmt* lastStmt;

    void execute();
};


#endif //COMPILER_WHILE_H
