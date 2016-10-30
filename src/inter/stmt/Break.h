//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_BREAK_H
#define COMPILER_BREAK_H

#include "Stmt.h"
#include "../error/BreakError.h"

class Break: public Stmt {
public:
    Break() {};
    int execute() {
        BreakError r = BreakError("break");
        throw r;
    };

};


#endif //COMPILER_BREAK_H
