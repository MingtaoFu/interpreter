//
// Created by mingtao on 10/26/16.
//

#include "Decl.h"
#include "../../vm/Vm.h"
#include <iostream>

Decl::Decl(Var * id1) {
    var = id1;
}

void Decl::execute() {
    Word * word = (Word*)var->token;
    std::string name = ((Word *)var->token)->lexeme;
    Vm::top->put(name, *var->id);
    std::cout << "发生声明: " << name << std::endl;
    Vm::top->printCurrentVar();
}