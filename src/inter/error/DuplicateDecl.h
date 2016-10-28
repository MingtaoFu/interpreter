//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_DUPLICATEDECL_H
#define COMPILER_DUPLICATEDECL_H


#include <stdexcept>
#include <iostream>

class DuplicateDecl: public std::runtime_error {
public:
    explicit DuplicateDecl(std::string);

};


#endif //COMPILER_DUPLICATEDECL_H
