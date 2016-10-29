//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_SYNTAXERROR_H
#define COMPILER_SYNTAXERROR_H


#include <stdexcept>
#include <iostream>

class SyntaxError: public std::runtime_error {
public:
    explicit SyntaxError(std::string);
};


#endif //COMPILER_SYNTAXERROR_H
