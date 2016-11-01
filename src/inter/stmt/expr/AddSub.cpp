//
// Created by mingtao on 10/29/16.
//

#include <iostream>
#include "AddSub.h"
#include "../../../lexer/Tag.h"
#include "Math.h"
#include "../../../vm/Vm.h"

AddSub::AddSub(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {
}

int AddSub::execute() {
    int value1, value2;
    if(expr_l->isVar()) {
        value2 = expr_r->execute();
        value1 = expr_l->execute();
    } else {
        value1 = expr_l->execute();
        value2 = expr_r->execute();
    }

    //std::cout << "发生加/减法 \t\t行号: " << lexline << std::endl;
    Vm::printLine(lexline);
    if(op->tag == Tag::PLUS) {
        //std::cout << "执行 addsub，发生加/减法: " << value1 << " + " << value2 << std::endl;
        return value1 + value2;
    }
    //std::cout << "执行 addsub，发生加/减法: " << value1 << " - " << value2 << std::endl;
    return value1 - value2;
}