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
    Vm::top->put(((Word *)id->op)->lexeme, *id);
    std::cout << ((Word *)id->op)->lexeme << std::endl;
    std::cout << "发生声明" << std::endl;
    Vm::top->printCurrentVar();
}