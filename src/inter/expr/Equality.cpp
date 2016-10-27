//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Equality.h"

Equality::Equality(Token * token, Expr * expr3, Expr * expr4):Math(token, expr3, expr4) {
}

void Equality::execute() {
    std::cout << "执行 equality，发生等于/不等于比较运算" << std::endl;
}
