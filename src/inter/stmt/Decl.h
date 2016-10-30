//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H


#include <vector>
#include "Stmt.h"
#include "expr/Var.h"

class Decl: public Stmt {
protected:
    std::vector<std::pair<Var*, Expr*>> * decls;
public:
    //Var * var;
    //Expr * expr;
    int execute();
    void put(Var *, Expr *);
    Decl();
};


#endif //COMPILER_DECL_H
