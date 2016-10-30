//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_VAR_H
#define COMPILER_VAR_H


#include "Factor.h"
#include "../../../lexer/Word.h"
#include "Id.h"

///
/// \brief 变量类
///


class Var: public Factor {
public:
    ///
    /// \param word : 变量名的 token
    ///
    Var(Word *);
    Id * id; ///< 作用域的内的id
    /// \return 变量的值
    int execute();
    /// 设置变量的值
    void setValue(int);
};


#endif //COMPILER_VAR_H
