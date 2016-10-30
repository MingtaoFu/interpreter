//
// Created by BluesJiang on 2016/10/28.
//

#ifndef COMPILER_PRINTF_H
#define COMPILER_PRINTF_H

#include "Stmt.h"
#include "expr/Expr.h"
#include <vector>
#include <iostream>


class Printf: public Stmt{
public:
    std::vector<Expr*> exprs;

    int execute();

};


#endif //COMPILER_PRINTF_H
