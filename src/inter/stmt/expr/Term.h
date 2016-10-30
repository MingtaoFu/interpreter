//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_TERM_H
#define COMPILER_TERM_H


#include "Math.h"
#include "Unary.h"

///
/// \brief 乘除运算符类
///

class Term: public Math {
public:
    /// \param  token   : 运算符
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    Term(Token * token, Expr * expr1, Expr * expr2);
    /// 计算
    int execute();
};


#endif //COMPILER_TERM_H
