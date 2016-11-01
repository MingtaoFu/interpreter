//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_BREAKERROR_H
#define COMPILER_BREAKERROR_H

#include <stdexcept>
#include <iostream>
///
/// \brief Break类
///
/// 用于抛出break的异常\n
/// 便于While循环提前中断
///
class BreakError: public std::runtime_error{
public:
    explicit BreakError(std::string) ;
};


#endif //COMPILER_BREAKERROR_H
