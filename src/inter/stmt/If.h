//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_IF_H
#define COMPILER_IF_H


#include "Stmt.h"
#include "expr/Expr.h"
#include <vector>
///
/// \brief if语句类
///
class If: public Stmt {
protected:
    Expr * equality; ///< if判断表达式
    Stmt * stmt1;  ///< if语句块部分
    Stmt * stmt2;  ///< else语句块部分,没有则为NULL

public:
    /// 开始执行if语句
    int execute();
    /// \param expr  : 条件表达式
    /// \param stmt1 : if 语句块
    /// \param stmt2 : else 语句块
    If(Expr *, Stmt *, Stmt *);
};


#endif //COMPILER_IF_H
