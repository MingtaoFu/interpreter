//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_BREAK_H
#define COMPILER_BREAK_H

#include "Stmt.h"

class Break: public Stmt {
public:
    Stmt* stmt;
    Break();
    void execute();

};


#endif //COMPILER_BREAK_H
