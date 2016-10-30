//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H


#include "../Node.h"

class Stmt: public Node {
public:
    virtual int execute();
    int lineNumber;
};


#endif //COMPILER_STMT_H
