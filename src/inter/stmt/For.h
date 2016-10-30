//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_FOR_H
#define COMPILER_FOR_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "expr/Expr.h"

class For: public Stmt {
public:
    Stmt* initStmt;
    Expr* equal;
    Stmt* increasement;
    Stmt* stmt;
    int execute();

};


#endif //COMPILER_FOR_H
