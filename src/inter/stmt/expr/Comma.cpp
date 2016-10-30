//
// Created by mingtao on 10/29/16.
//

#include <iostream>
#include "Comma.h"

Comma::Comma(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {
}

int Comma::execute() {
    expr_l->execute();
    int value = expr_r->execute();
    std::cout << "发生逗号运算" << std::endl;
    return value;
}