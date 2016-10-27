//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILE_NUM_H
#define COMPILE_NUM_H


#include "Token.h"
#include "Tag.h"

class Num: Token{
public:
    int value;
    Num(int v);
    std::string toString();
};


#endif //COMPILE_NUM_H
