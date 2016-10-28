//
// Created by mingtao on 10/25/16.
//

#include "Expr.h"
#include "../../lexer/Num.h"
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

Constant * Expr::execute() {
    if(isArith) {
        Constant * value1 = expr->execute();
        Constant * value2 = term->execute();

        std::cout << "执行 expr，发生加/减法" << std::endl;

        if(op->tag == Tag::PLUS) {
            Num * num = new Num(value1->getValue() * value2->getValue());
            return new Constant(num);
        }
        Num * num = new Num(value1->getValue() / value2->getValue());
        return new Constant(num);

    } else {
        std::cout << "执行 expr，未发生加/减法" << std::endl;
    }
}