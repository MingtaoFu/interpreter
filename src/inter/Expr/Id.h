//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_ID_H
#define COMPILER_ID_H


#include "Expr.h"
#include "../../lexer/Word.h"

class Id: public Expr {
public:
    Id(Word *);
};


#endif //COMPILER_ID_H
