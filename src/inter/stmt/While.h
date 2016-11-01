//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_WHILE_H
#define COMPILER_WHILE_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include "../../vm/Vm.h"
#include <iostream>
///
/// \brief while循环语句类
///
class While: public Stmt {
public:
    Expr* equality = NULL; ///< 条件判断语句
    Stmt* stmt = NULL; ///< 循环体
    /// 执行While语句块
    int execute();
};


#endif //COMPILER_WHILE_H
