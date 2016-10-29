//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_DOWHILE_H
#define COMPILER_DOWHILE_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "../expr/Expr.h"
class DoWhile: public Stmt {
public:
    Stmt* stmt;
    Expr* expr;

    void execute();



};


#endif //COMPILER_DOWHILE_H
