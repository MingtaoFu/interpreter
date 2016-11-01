//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_SYNTAXERROR_H
#define COMPILER_SYNTAXERROR_H


#include <stdexcept>
#include <iostream>
///
/// \brief 语法错误类
///
/// 在语法分析时, 若是匹配项与语法不一致时
/// 就会抛出此错误
class SyntaxError: public std::runtime_error {
public:
    explicit SyntaxError(std::string);
};


#endif //COMPILER_SYNTAXERROR_H
