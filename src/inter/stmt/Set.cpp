//
// Created by mingtao on 10/26/16.
//

#include "Set.h"
#include "../../vm/Vm.h"
#include "../error/VarNotFound.h"
#include <iostream>

Set::Set(Var * var1, Expr * expr1) {
    var = var1;
    expr = expr1;
}

void Set::execute() {
    std::string var_name = ((Word*)var->token)->lexeme;
    Id * id = Vm::top->get(var_name);
    if(!id) {
        throw VarNotFound(var_name);
    } else {
        var->id = id;
        int a = expr->execute();
        var->setValue(a);
        std::cout << "发生赋值"<<a << std::endl;
    }
}