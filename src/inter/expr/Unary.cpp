//
// Created by mingtao on 10/26/16.
//

#include "Unary.h"
#include <iostream>

Unary::Unary(Token * token, Expr * factor1):Math(token, NULL, factor1) {
    
}

Constant * Unary::execute() {
    std::cout << "执行 unary，发生正/负运算" << std::endl;
    Constant * _value = ((Factor *)expr2)->execute();

    if(op->tag == Tag::PLUS) {
        return _value;
    } else {
        Constant * value = new Constant(-_value->value);
        return value;
    }
}
