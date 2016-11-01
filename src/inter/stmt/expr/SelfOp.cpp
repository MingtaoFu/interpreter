//
// Created by mingtao on 10/27/16.
//

#include "SelfOp.h"
#include "../../../lexer/Num.h"
#include "Var.h"
#include "../../../vm/Vm.h"
#include <iostream>

SelfOp::SelfOp(Token * token, Expr * factor): Math(token, factor, NULL) {
}

int SelfOp::execute() {
    //std::cout << "发生自增/自减运算 \t行号: " << lexline << std::endl;
    Vm::printLine(lexline);
    int value = expr_l->execute();

    // 在此执行自增/减
    if(op->tag == Tag::INCRE) {
        ((Var *)expr_l)->id->value++;
    } else {
        ((Var *)expr_l)->id->value--;
    }

    return value;
}
