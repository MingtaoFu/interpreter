//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "Rel.h"

Rel::Rel(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {

}

void Rel::execute() {
    std::cout << "执行 rel，发生大于/小于比较运算" << std::endl;
}