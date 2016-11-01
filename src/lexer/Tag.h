//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILE_TAG_H
#define COMPILE_TAG_H

///
/// \brief tag类
///
/// 用于定义所有关键符号
/// 的枚举值
///
class Tag {
public:
    static const int
    //标识符
            ID = 256,
    //常量
            NUM = 257,
    //分隔符
            Semicolon = ';',
            L_PARENTHESE = '(',
            R_PARENTHESE = ')',
            L_BRACE = '{',
            R_BRACE = '}',
            COMMA  = ',',
    //运算符
            PLUS = '+',
            SUB = '-',
            MULT = '*',
            DIV = '/',
            LT = '<',
            GT = '>',
            GE = 264,
            LE = 265,
            NE = 266,
            EQ = 267,
            INCRE = 268,
            DECRE = 269,
    //关键字
            INT = 258,
            IF = 259,
            ELSE = 260,
            FOR = 261,
            DO = 262,
            WHILE = 263,
            BREAK = 270,
    //函数
            PRINTF = 271;
};


#endif //COMPILE_TAG_H
