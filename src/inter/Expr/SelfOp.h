//
// Created by mingtao on 10/27/16.
//

#ifndef COMPILER_SELFOP_H
#define COMPILER_SELFOP_H


#include "Math.h"

class SelfOp: public Math {
public:
    SelfOp(Token *, Expr *);
};


#endif //COMPILER_SELFOP_H
