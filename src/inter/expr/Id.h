//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_ID_H
#define COMPILER_ID_H


#include "../../lexer/Word.h"
#include "Factor.h"
#include "Constant.h"

class Id: public Factor {
public:
    Id(Word *);
    Constant * value;

    Constant * execute();
};


#endif //COMPILER_ID_H
