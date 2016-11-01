//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_BREAK_H
#define COMPILER_BREAK_H

#include "Stmt.h"
#include "../error/BreakError.h"
///
/// \brief 循环中断类
///
class Break: public Stmt {
public:
    /// 执行循环中断,抛出中断异常
    int execute();

};


#endif //COMPILER_BREAK_H
