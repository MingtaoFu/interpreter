//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_EQUALITY_H
#define COMPILER_EQUALITY_H


#include "Math.h"
#include "Rel.h"
#include "../../../lexer/Token.h"

///
/// \brief 等于不等于表达式类
///
class Equality: public Math {
public:
    /// \param  token   : 标识运算符的 token
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    Equality(Token * token, Expr * expr1, Expr *expr2);
    /// \return 执行后的值
    int execute();
};


#endif //COMPILER_EQUALITY_H
