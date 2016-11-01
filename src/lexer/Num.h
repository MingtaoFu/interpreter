//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILE_NUM_H
#define COMPILE_NUM_H


#include "Token.h"
#include "Tag.h"
///
/// \brief 数字类
///
/// 数学运算中的基本元素
///
class Num: public Token{
public:
    int value; ///< 该数字的值
    /// \param v : 该数字的值
    Num(int v);
    /// 将数字转成字符串便于输出
    std::string toString();
};


#endif //COMPILE_NUM_H
