//
// Created by mingtao on 10/26/16.
//

#include "Unary.h"
#include "../../../lexer/Tag.h"
#include "../../../vm/Vm.h"
#include <iostream>

Unary::Unary(Token * token, Expr * factor1):Math(token, NULL, factor1) {
    
}

int Unary::execute() {
    //std::cout << "发生正/负运算 \t行号: "  << lexline << std::endl;
    Vm::printLine(lexline);
    int _value = ((Factor *)expr_r)->execute();

    if(op->tag == Tag::PLUS) {
        return _value;
    } else {
        return -_value;
    }
}
