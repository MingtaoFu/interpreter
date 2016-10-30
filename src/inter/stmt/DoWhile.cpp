//
// Created by BluesJiang on 2016/10/29.
//

#include "DoWhile.h"



int DoWhile::execute() {
    std::cout << "执行 do while :" << std::endl;
    do {
        try {
//            std::cout << "执行循环体 \t行号: " << stmt->lineNumber << std::endl;
            stmt->execute();
        } catch (BreakError aBreak) {
            std::cout << "do while 因 break 退出" << std::endl;
            break;
        }
        std::cout << "执行while判断 \t行号: " << expr->lexline << std::endl;
    } while (expr->execute() != 0);
    return 0;
}