//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Equality.h"
#include "../../lexer/Tag.h"

Equality::Equality(Token * token, Expr * expr3, Expr * expr4):Math(token, expr3, expr4) {
}

int Equality::execute() {

    int value1 = expr1->execute();
    int value2 = expr2->execute();

    std::cout << "执行 equality，发生等于/不等于比较运算" << std::endl;

    if(op->tag == Tag::EQ) {
        return value1 == value2;
    }
    return value1 != value2;
}
