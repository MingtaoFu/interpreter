//
// Created by mingtao on 10/29/16.
//

#ifndef COMPILER_ADDSUB_H
#define COMPILER_ADDSUB_H


#include "Math.h"

class AddSub: public Math {
public:
    AddSub(Token *, Expr *, Expr *);

    int execute();
};


#endif //COMPILER_ADDSUB_H
