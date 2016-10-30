//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H


#include "../Stmt.h"
#include "../../../lexer/Token.h"

///
/// \brief 运算表达式类
///
class Expr: public Stmt{
public:
    Token * op; ///< 标识操作的 token
    /// \param  token : 标识运算因子类型的 token
    Expr(Token *);
    /// \return 执行后的值
    virtual int execute();
    virtual bool isVar();
};


#endif //COMPILER_EXPR_H
