//
// Created by mingtao on 10/26/16.
//

#include "Term.h"
#include "../../lexer/Tag.h"
#include <iostream>

Term::Term(Token * token, Expr * term1, Expr * unary1): Math(token, term1, unary1) {
}

int Term::execute() {
    int value1 = expr1->execute();
    int value2 = expr2->execute();

//    std::cout << "执行 term，发生乘/除法" << std::endl;

    if(op->tag == Tag::MULT) {
        return value1 * value2;
    }
    return value1 / value2;
}
