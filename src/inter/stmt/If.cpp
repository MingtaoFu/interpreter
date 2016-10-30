//
// Created by mingtao on 10/26/16.
//

#include <iostream>
#include "If.h"
#include "../error/BreakError.h"
#include "../../vm/Vm.h"

int If::execute() {
    std::cout << "执行if的判断 \t\t行号: " << equality->lexline << std::endl;
    int value = equality->execute();
    try {
        if(value == 0) {
            if(stmt2) {
                std::cout << "执行else内语句 \t行号: "  << stmt2->lexline << std::endl;
                stmt2->execute();

            }
        } else {
            std::cout << "执行 if 内语句 \t行号: "  << stmt1->lexline << std::endl;
            stmt1->execute();

        }
    } catch (BreakError aBreak) {
        throw (aBreak);
    }
    return 0;
}

If::If(Expr * equality1, Stmt * stmt3, Stmt * stmt4) {
    equality = equality1;
    stmt1 = stmt3;
    stmt2 = stmt4;
}