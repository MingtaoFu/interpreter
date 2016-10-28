//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_EQUALITY_H
#define COMPILER_EQUALITY_H


#include "Math.h"
#include "Rel.h"
#include "../../lexer/Token.h"

class Equality: public Math {
public:
    Equality(Token *, Expr *, Expr *);

    int execute();
};


#endif //COMPILER_EQUALITY_H
