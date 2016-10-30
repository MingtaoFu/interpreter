//
// Created by mingtao on 10/29/16.
//

#ifndef COMPILER_COMMA_H
#define COMPILER_COMMA_H


#include <vector>
#include "Expr.h"
#include "Math.h"

class Comma: public Math {
public:
    Comma(Token *, Expr *, Expr *);

    int execute();
};


#endif //COMPILER_COMMA_H
