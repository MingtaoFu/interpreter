//
// Created by mingtao on 10/26/16.
//

#include "Set.h"
#include <iostream>

Set::Set(Id * id1, Expr * expr1) {
    id = id1;
    expr = expr1;
}

void Set::execute() {
    expr->execute();
    std::cout << "发生赋值" << std::endl;
}