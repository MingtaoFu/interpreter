//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VARNOTFOUND_H
#define COMPILER_VARNOTFOUND_H


#include <stdexcept>

class VarNotFound: public std::runtime_error {
public:
    explicit VarNotFound(std::string);
};


#endif //COMPILER_VARNOTFOUND_H
