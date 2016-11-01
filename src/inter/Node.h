//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

#include <string>
///
/// \brief Node类
///
/// 所有的语句内容都算是抽象语法树中的一个节点
/// 所有的语句与表达式都是该类的子类
///
class Node {
protected:
    ///< 节点抛出异常
    void error(std::string);

public:
    int lexline = 0; ///< 该节点位于的行号
    /// 用于初始化节点行号
    Node();
};


#endif //COMPILER_NODE_H
