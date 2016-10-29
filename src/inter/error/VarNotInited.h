//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VARNOTINITED_H
#define COMPILER_VARNOTINITED_H


#include <stdexcept>
#include <iostream>

class VarNotInited: std::runtime_error {
public:
    explicit VarNotInited(std::string);
};


#endif //COMPILER_VARNOTINITED_H
