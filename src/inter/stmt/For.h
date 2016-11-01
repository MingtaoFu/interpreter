//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_FOR_H
#define COMPILER_FOR_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "expr/Expr.h"
#include "../../vm/Vm.h"
#include "../../symbols/Env.h"
///
/// \brief for循环语句类
///
class For: public Stmt {
public:
    Stmt* initStmt; ///<  初始化语句
    Expr* equal; ///< 条件判断语句
    Stmt* increasement; ///< 循环条件增长语句
    Stmt* stmt; ///< 循环体语句块
    /// 执行for循环语句
    int execute();

};


#endif //COMPILER_FOR_H
