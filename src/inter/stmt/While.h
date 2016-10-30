//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_WHILE_H
#define COMPILER_WHILE_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "../../vm/Vm.h"
#include <iostream>

class While: public Stmt {
public:
    Expr* equality = NULL;
    Stmt* stmt = NULL;
    While(){};
    int execute();
};


#endif //COMPILER_WHILE_H
