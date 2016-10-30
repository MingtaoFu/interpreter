//
// Created by mingtao on 10/27/16.
//

#ifndef COMPILER_SELFOP_H
#define COMPILER_SELFOP_H


#include "Math.h"
#include "../../stmt/Stmt.h"

///
/// \brief 赋值运算符类
///

class SelfOp: public Math {
public:
    /// \param  token   : 运算符
    /// \param  expr    : 表达式
    SelfOp(Token * token, Expr * expr);
    /// 返回复制后的变量值
    int execute();
};


#endif //COMPILER_SELFOP_H
