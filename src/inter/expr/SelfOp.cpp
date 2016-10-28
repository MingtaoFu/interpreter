//
// Created by mingtao on 10/27/16.
//

#include "SelfOp.h"
#include "Factor.h"
#include "../../lexer/Num.h"
#include <iostream>

SelfOp::SelfOp(Token * token, Expr * factor): Math(token, factor, NULL) {
}

Constant * SelfOp::execute() {
    std::cout << "执行selfop，发生自增/自减运算" << std::endl;

    Constant * _value = expr1->execute();
    Constant * value = new Constant(_value->value);

    // 在此执行自增/减
    if(op->tag == Tag::INCRE) {
        ((Factor *)expr1)->id->value++;
    } else {
        ((Factor *)expr1)->id->value--;
    }

    return value;
}
