//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_IF_H
#define COMPILER_IF_H


#include "Stmt.h"
#include "Expr/Expr.h"
#include <vector>

class If: public Stmt {
protected:
    std::vector<std::pair<Expr, Stmt>> * if_then;

public:
    void push_items(std::pair<Expr, Stmt>);
};


#endif //COMPILER_IF_H
