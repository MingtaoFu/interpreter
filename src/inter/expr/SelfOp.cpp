//
// Created by mingtao on 10/27/16.
//

#include "SelfOp.h"
#include <iostream>

SelfOp::SelfOp(Token * token, Expr * factor): Math(token, factor, NULL) {
}

void SelfOp::execute() {
    std::cout << "执行selfop，发生自增/自减运算" << std::endl;
}
