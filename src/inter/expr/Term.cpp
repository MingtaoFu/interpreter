//
// Created by mingtao on 10/26/16.
//

#include "Term.h"
#include <iostream>

Term::Term(Token * token, Expr * term1, Expr * unary1): Math(token, term1, unary1) {

}

void Term::execute() {
    std::cout << "执行 term，发生乘/除法" << std::endl;
}
