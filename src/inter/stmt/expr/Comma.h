//
// Created by mingtao on 10/29/16.
//

#ifndef COMPILER_COMMA_H
#define COMPILER_COMMA_H


#include <vector>
#include "Expr.h"
#include "Math.h"

///
/// \brief 逗号表达式类
///
class Comma: public Math {
public:
    /// \param  token   : 逗号的 token
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    Comma(Token *, Expr *, Expr *);
    /// \return 右表达式的值
    int execute();
};


#endif //COMPILER_COMMA_H
