//
// Created by mingtao on 10/29/16.
//

#include <iostream>
#include "AddSub.h"
#include "../../../lexer/Tag.h"
#include "Math.h"

AddSub::AddSub(Token * token, Expr * expr1, Expr * expr2): Math(token, expr1, expr2) {
}

int AddSub::execute() {
    int value1 = expr_l->execute();
    int value2 = expr_r->execute();

    if(op->tag == Tag::PLUS) {
        //std::cout << "执行 addsub，发生加/减法: " << value1 << " + " << value2 << std::endl;
        return value1 + value2;
    }
    //std::cout << "执行 addsub，发生加/减法: " << value1 << " - " << value2 << std::endl;
    return value1 - value2;
}