//
// Created by mingtao on 10/26/16.
//

#include "Decl.h"
#include "../../vm/Vm.h"
#include <iostream>

Decl::Decl() {
    decls = new std::vector<std::pair<Var*, Expr*>>();
}

void Decl::execute() {
    for(auto &i : *decls) {
        Var * var = i.first;
        Expr * expr = i.second;

        if(expr) {
            var->setValue(expr->execute());
        }

        Word * word = (Word*)var->token;
        std::string name = word->lexeme;
        Vm::top->put(name, *var->id);
        std::cout << "发生声明: " << name << std::endl;
        Vm::top->printCurrentVar();
    }
}

void Decl::put(Var * var, Expr * expr1) {
    std::pair<Var*, Expr*> pair(var, expr1);
    decls->push_back(pair);
}