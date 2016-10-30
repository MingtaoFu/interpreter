//
// Created by mingtao on 10/29/16.
//

#ifndef COMPILER_ADDSUB_H
#define COMPILER_ADDSUB_H


#include "Math.h"

///
/// \brief 加减表达式类
///
class AddSub: public Math {
public:
    /// \param  token   : 运算符的 token
    /// \param  expr1   : 左表达式
    /// \param  expr2   : 右表达式
    AddSub(Token * token, Expr * expr1, Expr * expr2);
    /// \return 运算后的值
    int execute();
};


#endif //COMPILER_ADDSUB_H
