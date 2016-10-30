//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_VM_H
#define COMPILER_VM_H

#include "../inter/stmt/Block.h"
#include <iostream>
#include <fstream>

///
/// \brief 虚拟机类
///
/// 用于执行整个抽象语法树
///
class Vm {
private:
    static int currentLine; ///< 运行到的当前行

protected:
    Block * entry;  ///< 语法树的入口

public:
    static Env * top; ///< 当前运行的变量环境
    /// 输出行号
    static void printLine(int lineNumber);
    /// 执行整个语法树
    void execute();
    /// 设置语法树入口
    void setEntry(Block *);
    /// \param block : 程序运行的初始block
    Vm(Block *);
};


#endif //COMPILER_VM_H
