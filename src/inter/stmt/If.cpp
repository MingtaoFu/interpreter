//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "If.h"

void If::execute() {
    std::cout << "进入 if 语句, " << (stmt2 ? "带有": "没有") << " else 语句" << std:: endl;
    int value = equality->execute();
    if(value == 0) {
        std::cout << "if 条件不满足" << std::endl;
        if(stmt2) {
            stmt2->execute();
        }
    } else {
        std::cout << "if 条件满足" << std::endl;
        stmt1->execute();
    }
}

If::If(Expr * equality1, Stmt * stmt3, Stmt * stmt4) {
    equality = equality1;
    stmt1 = stmt3;
    stmt2 = stmt4;
}