//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_ENV_H
#define COMPILER_ENV_H

#include <map>
#include "../lexer/Token.h"
#include "../inter/expr/Id.h"

class Env {
private:
    std::map<Token, Id> table;

protected:
    Env * prev;
    Id * _get(Token);

public:
    Env(Env *);
    void put(Token, Id);
    Id * get(Token);
};


#endif //COMPILER_ENV_H
