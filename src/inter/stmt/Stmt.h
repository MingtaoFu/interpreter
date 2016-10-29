//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H


#include "../Node.h"

class Stmt: public Node {
public:
    int lineNumber;
    virtual void execute();
};


#endif //COMPILER_STMT_H
