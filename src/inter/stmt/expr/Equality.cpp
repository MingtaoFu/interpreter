//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Equality.h"
#include "../../../lexer/Tag.h"
#include "../../../vm/Vm.h"

Equality::Equality(Token * token, Expr * expr3, Expr * expr4):Math(token, expr3, expr4) {
}

int Equality::execute() {

    int value1 = expr_l->execute();
    int value2 = expr_r->execute();

    std::cout << "发生等于/不等于比较运算 \t\t行号: " << lexline << std::endl;
    Vm::printLine(lexline);
    if(op->tag == Tag::EQ) {
        return value1 == value2;
    }
    return value1 != value2;
}
