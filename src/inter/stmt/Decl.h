//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H


#include "Stmt.h"
#include "../expr/Id.h"
#include "../expr/Var.h"

class Decl: public Stmt {
public:
    Var * var;
    Decl(Var *);
    void execute();
};


#endif //COMPILER_DECL_H
