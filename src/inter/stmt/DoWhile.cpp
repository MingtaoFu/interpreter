//
// Created by BluesJiang on 2016/10/29.
//

#include "DoWhile.h"



void DoWhile::execute() {
    std::cout << "执行 do while :" << std::endl;
    do {
        try {
            stmt->execute();
        } catch (BreakError aBreak) {
            std::cout << "do while 因 break 退出" << std::endl;
            break;
        }

    } while (expr->execute() != 0);
}