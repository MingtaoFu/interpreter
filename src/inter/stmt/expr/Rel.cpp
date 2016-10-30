//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Rel.h"
#include "../../../lexer/Tag.h"
#include "../../../vm/Vm.h"

Rel::Rel(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {

}

int Rel::execute() {
    int value1 = expr_l->execute();
    int value2 = expr_r->execute();

//    std::cout << "发生大于/小于比较运算\t 行号: " << lexline << std::endl;
    Vm::printLine(lexline);
    switch (op->tag) {
        case Tag::LT:
            return value1 < value2;
        case Tag::GT:
            return value1 > value2;
        case Tag::LE:
            return value1 <= value2;
        default:
            return value1 >= value2;
    }
}