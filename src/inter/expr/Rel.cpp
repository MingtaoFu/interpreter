//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Rel.h"
#include "../../lexer/Tag.h"

Rel::Rel(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {

}

int Rel::execute() {
    int value1 = expr1->execute();
    int value2 = expr2->execute();

    std::cout << "执行 rel，发生大于/小于比较运算" << std::endl;

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