//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H


#include "Factor.h"
#include "Math.h"

class Constant: public Node{

public:
    Constant(int);
    int value;

    Constant * execute();
};


#endif //COMPILER_CONSTANT_H
