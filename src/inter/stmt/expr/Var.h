//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VAR_H
#define COMPILER_VAR_H


#include "Factor.h"
#include "../../../lexer/Word.h"
#include "Id.h"

class Var: public Factor {
public:
    bool isVar();
    Var(Word *);
    Id * id;

    int execute();
    void setValue(int);
};


#endif //COMPILER_VAR_H
