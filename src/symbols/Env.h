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
    std::map<std::string, Id> table;

protected:
    Env * prev;
    Id * _get(std::string);

public:
    Env(Env *);
    void put(std::string, Id);
    Id * get(std::string);

    void printCurrentVar();
    void printAllVar();
};


#endif //COMPILER_ENV_H
