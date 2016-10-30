//
// Created by mingtao on 10/27/16.
//

#ifndef COMPILER_INIT_H
#define COMPILER_INIT_H


#include "Stmt.h"

class Init: public Stmt {
public:
    int execute();
};


#endif //COMPILER_INIT_H
