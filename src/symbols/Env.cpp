//
// Created by mingtao on 10/25/16.
//

#include "Env.h"

Env::Env(Env* n) {
    table = std::map<Token, Id>();
    prev = n;
}

void Env::put(Token token, Id id) {
    table.insert(std::pair<Token, Id>(token, id));
}

/**
 * 在当前表中查找
 */
Id * Env::_get(Token token) {
    std::map<Token, Id>::iterator iterator = table.find(token);
    if(iterator != table.end()) {
        return &iterator->second;
    }
    return NULL;
}

/**
 * 在表链中查找
 * 迭代实现
 */
Id * Env::get(Token token) {
    Env* env = this;
    Id* id;
    while (env != NULL) {
        id = env->_get(token);
        if(id != NULL) {
            return id;
        } else {
            env = env->prev;
        }
    }
    return NULL;
}