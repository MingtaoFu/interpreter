//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H


#include <vector>
#include "Stmt.h"
#include "expr/Var.h"
///
/// \brief 声明变量语句类
///
class Decl: public Stmt {
protected:
    std::vector<std::pair<Var*, Expr*>> * decls; ///< 该语句中被声明的变量
public:
    ///< 执行变量声明
    int execute();
    /// 将变量与初始化用的表达式绑定
    /// \param var  : 被声明的变量
    /// \param expr : 初始化表达式
    void put(Var *, Expr *);
    /// 初始化变量数组
    Decl();
};


#endif //COMPILER_DECL_H
