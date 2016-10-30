//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H


#include "../Node.h"

///
/// \brief Stmt类
///
/// 所有语句,表达式的超类\n
/// 定义语句基本的行为
///

class Stmt: public Node {
public:

    ///
    /// \brief 抽象的执行方法
    ///
    /// 因为表达式以及各种语句都是可执行的\n
    /// 设立这个方法利用多态可以实现整个语法树的执行\n
    ///
    /// \return int : 表达式或语句执行后获得的值
    ///

    virtual int execute();
};


#endif //COMPILER_STMT_H
