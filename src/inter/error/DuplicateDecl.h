//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_DUPLICATEDECL_H
#define COMPILER_DUPLICATEDECL_H


#include <stdexcept>
#include <iostream>
///
/// \brief DuplicateDecl类
///
/// 重复定义变量错误\n
/// 若一个变量在一个同一个作用域中被声明了两次将抛出此错误
///
class DuplicateDecl: public std::runtime_error {
public:
    explicit DuplicateDecl(std::string);

};


#endif //COMPILER_DUPLICATEDECL_H
