//
// Created by mingtao on 10/26/16.
//

#include "Unary.h"
#include <iostream>

Unary::Unary(Token * token, Expr * factor1):Math(token, NULL, factor1) {
    
}

void Unary::execute() {
    std::cout << "执行 unary，发生正/负运算" << std::endl;
}
