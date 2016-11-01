//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_ENV_H
#define COMPILER_ENV_H

#include <map>
#include "../lexer/Token.h"
#include "../inter/stmt/expr/Id.h"
///
/// \brief 变量环境类
///
class Env {
private:
    std::map<std::string, Id> table; ///< 当前环境的环境变量表

protected:
    Env * prev; ///< 上一层环境变量的指针
    /// 获取当前变量
    Id * _get(std::string);

public:
    /// \brief 初始化当前环境
    /// \param env : 上一层环境的指针
    Env(Env *);
    /// 向环境中添加新的变量
    void put(std::string, Id);
    /// 获取变量
    Id * get(std::string);
    /// 输出当前环境中的所有变量
    void printCurrentVar();
    /// 输出所有的环境中的变量
    void printAllVar();
};


#endif //COMPILER_ENV_H
