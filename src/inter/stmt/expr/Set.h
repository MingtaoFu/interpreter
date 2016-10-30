//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_SET_H
#define COMPILER_SET_H


#include "../Stmt.h"
#include "../expr/Expr.h"
#include "../expr/Id.h"
#include "../expr/Var.h"
#include "Math.h"

///
/// \brief 赋值运算符类
///

class Set: public Math {
public:
    /// \param  token   : 运算符
    /// \param  var     : 变量
    /// \param  expr    : 右表达式
    Set(Token * token, Var * var, Expr * expr);
    /// 返回复制后的变量值
    int execute();
};


#endif //COMPILER_SET_H
