//
// Created by mingtao on 10/28/16.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H


#include "Math.h"
///
/// \brief 常数类
///
class Constant: public Math{

public:
    /// \param token : 该常数的 token
    Constant(Token *);
    int value;  ///< 常数的值
    /// \return 常数的值
    int execute();
};


#endif //COMPILER_CONSTANT_H
