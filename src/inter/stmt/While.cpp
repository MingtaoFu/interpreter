//
// Created by BluesJiang on 2016/10/30.
//

#include "While.h"

int While::execute() {
        std::cout<< "开始 While 循环" << std::endl;
    std::cout << "执行While判断 \t行号: " << equality->lexline << std::endl;
    while (equality->execute() != 0){
        try {
            stmt->execute();
        }
        catch (BreakError aBreak) {
//                std::cout << "while因break退出" << std::endl;
            break;
        }
            std::cout << "执行While判断 \t行号: " << equality->lexline << std::endl;
    }
    std::cout<< "结束 While 循环" << std::endl;
    return 0;
}