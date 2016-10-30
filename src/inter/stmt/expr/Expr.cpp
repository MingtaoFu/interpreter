//
// Created by mingtao on 10/25/16.
//


#include <iostream>
#include "Expr.h"
#include "../../../lexer/Tag.h"

Expr::Expr(Token * token) {
    op = token;
}

int Expr::execute() {
//    std::cout << "执行 expr，未发生加/减法" << std::endl;
    return 0;
}

bool Expr::isVar() {
    return false;
}