//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILER_WORD_H
#define COMPILER_WORD_H


#include "Token.h"
#include "Tag.h"
///
/// \brief 字类
///
/// 代表关键字, 变量名等的
/// 对应类
///
class Word: public Token {
public:
    std::string lexeme = ""; ///< 改字的字符串信息
    /// \param s   : 该字的字符串
    /// \param tag : 该字的类型
    Word(std::string s, int tag);
    /// 将字输出成字符串
    /// \return 该字的字符串
    std::string toString();
};


#endif //COMPILER_WORD_H
