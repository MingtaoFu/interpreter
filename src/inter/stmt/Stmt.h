//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H


#include <sys/_types/_sigaltstack.h>
#include "../Node.h"

class Stmt: public Node {
public:
    static Stmt* Enclosing;
    static Stmt* after;
    virtual void execute();
};


#endif //COMPILER_STMT_H
