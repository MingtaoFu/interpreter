//
// Created by mingtao on 10/26/16.
//

#include "Block.h"
#include "../../vm/Vm.h"
#include "../error/BreakError.h"
#include <iostream>

int Block::execute() {
    // 保存当前块的运行环境
    Env * saveEnv = Vm::top;
    Vm::top = new Env(Vm::top);

    //std::cout << "进入块" << std::endl;
    this->setEnv(Vm::top);
    for(auto &stmt : stmts) {
        try {
            stmt->execute();
        } catch (BreakError aBreak) {
            throw (aBreak);
        }
    }
    //std::cout << "出块" << std::endl;
    Vm::top = saveEnv;
    return 0;
}

void Block::setEnv(Env * env) {
    this->env = env;
}

void Block::push_stmt(Stmt *stmt) {
    stmts.push_back(stmt);
}
