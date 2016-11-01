//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_DOWHILE_H
#define COMPILER_DOWHILE_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "expr/Expr.h"
///
/// \brief do-while循环语句类
///
class DoWhile: public Stmt {
public:
    Stmt* stmt; ///< 循环体语句
    Expr* expr; ///< 条件表达式
    /// 执行do-while循环语句
    int execute();
};


#endif //COMPILER_DOWHILE_H
