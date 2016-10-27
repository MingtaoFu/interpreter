//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_REL_H
#define COMPILER_REL_H


#include "Math.h"

class Rel: public Math {
public:
    Rel(Token *, Expr *, Expr *);

    void execute();
};


#endif //COMPILER_REL_H
