//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_ID_H
#define COMPILER_ID_H


#include "Factor.h"
#include "../../../lexer/Word.h"

///
/// \brief 变量的标示类
///
class Id: public Factor {
public:
    /// \param word : 变量的字 token
    Id(Word *);
    int value;  ///< id 的值
    /// 执行返回id的值
    int execute();
};


#endif //COMPILER_ID_H
