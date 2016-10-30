//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_UNARY_H
#define COMPILER_UNARY_H


#include "Math.h"
#include "Factor.h"
#include "../../../lexer/Token.h"

///
/// \brief 正负运算符类
///


class Unary: public Math {
public:
    /// \param token : 运算符 token
    /// \param expr : 被运算的表达式
    Unary(Token *, Expr *);
    /// \return 返回正负号计算后的值
    int execute();
};


#endif //COMPILER_UNARY_H
