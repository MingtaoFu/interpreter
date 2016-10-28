//
// Created by mingtao on 10/26/16.
//

#include "Set.h"
#include "../../vm/Vm.h"
#include "../error/VarNotFound.h"
#include <iostream>

Set::Set(Id * id1, Expr * expr1) {
    id = id1;
    expr = expr1;
}

void Set::execute() {
    std::string var_name = ((Word*)id->op)->lexeme;
    id =  Vm::top->get(var_name);
    if(!id) {
        throw VarNotFound(var_name);
    } else {
        expr->execute();
        std::cout << "发生赋值" << std::endl;
    }
}