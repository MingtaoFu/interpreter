//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Rel.h"
#include "../../lexer/Tag.h"

Rel::Rel(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {

}

Constant * Rel::execute() {
    Constant * value1 = expr1->execute();
    Constant * value2 = expr2->execute();

    std::cout << "执行 rel，发生大于/小于比较运算" << std::endl;

    switch (op->tag) {
        case Tag::LT:
            return new Constant(value1->value < value2->value);
        case Tag::GT:
            return new Constant(value1->value > value2->value);
        case Tag::LE:
            return new Constant(value1->value <= value2->value);
        default:
            return new Constant(value1->value >= value2->value);
    }
}