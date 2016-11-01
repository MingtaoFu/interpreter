//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VARNOTFOUND_H
#define COMPILER_VARNOTFOUND_H


#include <stdexcept>
#include <iostream>

///
/// \brief VarNotFound类
///
/// 未定义变量错误\n
/// 若在作用域中使用未声明的变量,将抛出此错误
///
class VarNotFound: public std::runtime_error {
public:
    explicit VarNotFound(std::string);
};


#endif //COMPILER_VARNOTFOUND_H
