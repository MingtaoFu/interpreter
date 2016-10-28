//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_TERM_H
#define COMPILER_TERM_H


#include "Math.h"
#include "Unary.h"

class Term: public Math {
public:
    Term(Token *, Expr *, Expr *);

    int execute();
};


#endif //COMPILER_TERM_H
