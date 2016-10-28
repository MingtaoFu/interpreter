//
// Created by mingtao on 10/26/16.
//

#include "Decl.h"
#include "../../vm/Vm.h"
#include <iostream>

Decl::Decl(Id * id1) {
    id = id1;
}

void Decl::execute() {
    std::string name = ((Word *)id->op)->lexeme;
    Vm::top->put(name, *id);
    std::cout << "发生声明: " << name << std::endl;
    Vm::top->printCurrentVar();
}