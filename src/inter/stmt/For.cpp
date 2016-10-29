//
// Created by BluesJiang on 2016/10/29.
//

#include "For.h"


void For::execute() {
    std::cout << "执行 for 循环" << std::endl;
    for (initStmt->execute(); equal->execute() ; increasement->execute()) {
        try {
            stmt->execute();
        } catch (BreakError aBreak) {
            std::cout << "for meet break" << std::endl;
            break;
        }

    }
    std::cout << "结束 for 循环" << std::endl;
}