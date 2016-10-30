//
// Created by mingtao on 10/26/16.
//

#include "Decl.h"
#include "../../vm/Vm.h"
#include <iostream>

Decl::Decl() {
    decls = new std::vector<std::pair<Var*, Expr*>>();
}

int Decl::execute() {
    for(auto &i : *decls) {
        Var * var = i.first;
        Expr * expr = i.second;
        if(expr) {
            Vm::printLine(expr->lexline);
            var->setValue(expr->execute());
            std::cout << "执行声明中赋值 \t行号: " << expr->lexline << std::endl;
        }

        Word * word = (Word*)var->token;
        std::string name = word->lexeme;
        Vm::top->put(name, *var->id);
    }
    return 0;
}

void Decl::put(Var * var, Expr * expr1) {
    std::pair<Var*, Expr*> pair(var, expr1);
    decls->push_back(pair);
}