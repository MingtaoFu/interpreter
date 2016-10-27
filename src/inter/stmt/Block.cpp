//
// Created by mingtao on 10/26/16.
//

#include "Block.h"

void Block::execute() {
    for(auto &stmt : stmts) {
        stmt->execute();
    }
}

void Block::setEnv(Env * env) {
    this->env = env;
}

void Block::push_stmt(Stmt *stmt) {
    stmts.push_back(stmt);
}
