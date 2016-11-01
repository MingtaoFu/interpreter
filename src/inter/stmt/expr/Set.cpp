//
// Created by mingtao on 10/26/16.
//

#include "Set.h"
#include "../../../vm/Vm.h"
#include "../../error/VarNotFound.h"
#include <iostream>

Set::Set(Token * token, Var * var1, Expr * expr1): Math(token, var1, expr1) {
}

int Set::execute() {
    Var * var = (Var*)expr_l;
    std::string var_name = ((Word*)var->token)->lexeme;
    Id * id = Vm::top->get(var_name);
    if(!id) {
        throw VarNotFound(var_name);
    } else {
        var->id = id;
        int a = expr_r->execute();
        var->setValue(a);
        //std::cout << "发生赋值 "<< a << "\t\t行号: " << lexline << std::endl;
        Vm::printLine(lexline);
        return a;
    }
}