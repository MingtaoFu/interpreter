//
// Created by mingtao on 10/26/16.
//

#include "Term.h"
#include <iostream>

Term::Term(Token * token, Expr * term1, Expr * unary1): Math(token, term1, unary1) {
}

Constant * Term::execute() {
    Constant * value1 = expr1->execute();
    Constant * value2 = expr2->execute();

    std::cout << "执行 term，发生乘/除法" << std::endl;

    if(op->tag == Tag::MULT) {
        return new Constant(value1->value * value2->value);
    }
    return new Constant(value1->value / value2->value);
}
