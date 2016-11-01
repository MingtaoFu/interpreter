//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_BLOCK_H
#define COMPILER_BLOCK_H


#include "Stmt.h"
#include "../../symbols/Env.h"
#include "Break.h"
#include <vector>

///
/// \brief 语句块类
///
class Block: public Stmt {
protected:
    std::vector<Stmt *> stmts; ///< 储存该块中的所有语句
    Env * env; ///< 储存当前的变量环境

public:
    /// 启动执行该块中的语句
    int execute();
    /// 设置变量环境
    void setEnv(Env *);
    /// 向块中添加语句
    void push_stmt(Stmt *);
};


#endif //COMPILER_BLOCK_H
