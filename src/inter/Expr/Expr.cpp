//
// Created by mingtao on 10/25/16.
//

#include "Expr.h"
#include <iostream>

Expr::Expr(Token * token) {
    op = token;
}

Expr::Expr(Token * token, Expr * expr1, Expr * term1) {
    op = token;
    expr = expr1;
    term = term1;
    isArith = true;
}

void Expr::execute() {
    if(isArith) {
        std::cout << "执行 expr，发生加/减法" << std::endl;
    } else {
        std::cout << "执行 expr，未发生加/减法" << std::endl;
    }
}