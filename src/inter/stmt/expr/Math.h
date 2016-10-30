//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_MATH_H
#define COMPILER_MATH_H


#include "../../../lexer/Token.h"
#include "Expr.h"

///
/// \brief 数学运算的根类
///

class Math: public Expr {
public:
    Expr * expr_l;  ///< 左表达式
    Expr * expr_r;  ///< 右表达式
    /// \param  token   : 运算符
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    Math(Token * token, Expr * expr1, Expr * expr2);
};


#endif //COMPILER_MATH_H
