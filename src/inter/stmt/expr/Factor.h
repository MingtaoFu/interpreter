//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_FACTOR_H
#define COMPILER_FACTOR_H


#include "Expr.h"
#include "Math.h"

///
/// \brief 运算因子类
///
class Factor: public Math {
public:
    Token * token;  ///< 标识运算因子类型的 token
    /// \param  token : 标识运算因子类型的 token
    Factor(Token *);
};


#endif //COMPILER_FACTOR_H
