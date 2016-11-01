//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VARNOTINITED_H
#define COMPILER_VARNOTINITED_H


#include <stdexcept>
#include <iostream>
///
/// \brief VarNotInited类
///
/// 未定义变量错误\n
/// 若在作用域中声明的变量未被初始化将抛出此错误
///
class VarNotInited: std::runtime_error {
public:
    explicit VarNotInited(std::string);
};


#endif //COMPILER_VARNOTINITED_H
