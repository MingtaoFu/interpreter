//
// Created by mingtao on 10/25/16.
//

#include <iostream>
#include "Env.h"
#include "../inter/error/DuplicateDecl.h"

Env::Env(Env* n) {
    table = std::map<std::string, Id>();
    prev = n;
}

void Env::put(std::string word, Id id) {
    if(!table.insert(std::pair<std::string, Id>(word, id)).second) {
        //std::cout << "Insertion failed. Key was present"<< std::endl;
        throw DuplicateDecl(word);
    }
}

/**
 * 在当前表中查找
 */
Id * Env::_get(std::string word) {
    std::map<std::string, Id>::iterator iterator = table.find(word);
    if(iterator != table.end()) {
        return &iterator->second;
    }
    return NULL;
}

/**
 * 在表链中查找
 * 迭代实现
 */
Id * Env::get(std::string word) {
    Env* env = this;
    Id* id;
    while (env != NULL) {
        id = env->_get(word);
        if(id != NULL) {
            return id;
        } else {
            env = env->prev;
        }
    }
    return NULL;
}

/**
 * 打印作用域链所有变量
 * 调试使用
 */
void Env::printAllVar() {
}

/**
 * 打印当前block作用域变量
 * 调试使用
 */
void Env::printCurrentVar() {
    auto map_it = this->table.cbegin();
    std::cout << "当前作用域变量[" << this->table.size() << "]: ";
    while (map_it != this->table.cend()) {
        std::cout << map_it->first << ",";
        ++map_it;
    }
    std::cout << std::endl;
}