//
// Created by BluesJiang on 2016/10/28.
//

#ifndef COMPILER_PRINTF_H
#define COMPILER_PRINTF_H

#include "Stmt.h"
#include "expr/Expr.h"
#include <vector>
#include <iostream>

///
/// \brief 输出语句块类
///
class Printf: public Stmt{
public:
    std::vector<Expr*> exprs; ///< 参数中的表达式
    /// 执行输出语句
    int execute();

};


#endif //COMPILER_PRINTF_H
