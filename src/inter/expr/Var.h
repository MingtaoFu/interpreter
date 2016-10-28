//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VAR_H
#define COMPILER_VAR_H


#include "Factor.h"

class Var: public Factor {
public:
    Var(Word *);
    Id * id;

    Constant * execute();
};


#endif //COMPILER_VAR_H
