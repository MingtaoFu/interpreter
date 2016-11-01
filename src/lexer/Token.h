//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILE_TOKEN_H
#define COMPILE_TOKEN_H

#include <string>
///
/// \brief token类
///
/// 语法分析器中解析的基本元素
/// 也是词法分析器中生成的元素
///
class Token {

public:
    int tag; ///< 该token的类型
    int line; ///< 该token所处的行号
    /// \param t : 初始化token的tag值
    Token(int t);
    /// \return 返回该token的信息
    virtual std::string toString();
    /// 重载token的比较符,用于比较token
    inline bool operator < (const Token t) const {
        return this->tag < t.tag;
    }
};


#endif //COMPILE_TOKEN_H
