//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_BLOCK_H
#define COMPILER_BLOCK_H


#include "Stmt.h"
#include "../../symbols/Env.h"
#include "Break.h"
#include <vector>

class Block: public Stmt {
protected:
    std::vector<Stmt *> stmts;
    Env * env;

public:
    std::vector<Break*> breaks;
    void execute();
    void setEnv(Env *);
    void push_stmt(Stmt *);
};


#endif //COMPILER_BLOCK_H
