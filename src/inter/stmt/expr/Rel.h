//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_REL_H
#define COMPILER_REL_H


#include "Math.h"

///
/// \brief 大小于运算符类
///

class Rel: public Math {
public:
    /// \param  token   : 运算符
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    Rel(Token * token, Expr * expr1, Expr * expr2);
    /// 返回复制后的变量
    int execute();
};


#endif //COMPILER_REL_H
