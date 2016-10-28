//
// Created by mingtao on 10/27/16.
//

#include "SelfOp.h"
#include "../../lexer/Num.h"
#include "Var.h"
#include <iostream>

SelfOp::SelfOp(Token * token, Expr * factor): Math(token, factor, NULL) {
}

int SelfOp::execute() {
    std::cout << "执行selfop，发生自增/自减运算" << std::endl;

    int value = expr1->execute();

    // 在此执行自增/减
    if(op->tag == Tag::INCRE) {
        ((Var *)expr1)->id->value++;
    } else {
        ((Var *)expr1)->id->value--;
    }

    return value;
}
