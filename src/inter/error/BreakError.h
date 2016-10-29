//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_BREAKERROR_H
#define COMPILER_BREAKERROR_H

#include <stdexcept>
#include <iostream>
class BreakError: public std::runtime_error{
public:
    explicit BreakError(std::string) ;
};


#endif //COMPILER_BREAKERROR_H
