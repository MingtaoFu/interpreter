//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H


#include "Stmt.h"
#include "Expr/Id.h"

class Decl: public Stmt {
public:
    Id * id;
    Decl(Id *);
    void execute();
};


#endif //COMPILER_DECL_H
