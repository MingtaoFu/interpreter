//
// Created by mingtao on 10/25/16.
//


#include <iostream>
#include "Expr.h"
#include "../../lexer/Tag.h"

Expr::Expr(Token * token) {
    op = token;
}

Expr::Expr(Token * token, Expr * expr1, Expr * term1) {
    op = token;
    expr = expr1;
    term = term1;
    isArith = true;
    lexline = token->line;
}

int Expr::execute() {
    if(isArith) {
        int value1 = expr->execute();
        int value2 = term->execute();

//        std::cout << "执行 expr，发生加/减法: " << value1 << " + " << value2 << std::endl;

        if(op->tag == Tag::PLUS) {
            return value1 + value2;
        }
        return value1 - value2;

    } else {
//        std::cout << "执行 expr，未发生加/减法" << std::endl;
    }
//    std::cout << "行号: " << lexline << std::endl;

}