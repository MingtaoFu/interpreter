//
// Created by BluesJiang on 2016/10/29.
//

#include "For.h"



int For::execute() {
    Env* savedEnv = Vm::top;
    Vm::top = new Env(Vm::top);

    std::cout << "开始 for 循环 \t行号: " << lexline << std::endl;
//    Vm::printLine(lexline);
    for (initStmt->execute(); equal->execute() ; increasement->execute()) {
        try {
//            std::cout << "执行 for-block \t行号: " << stmt->lineNumber << std::endl;
            stmt->execute();
        } catch (BreakError aBreak) {
            std::cout << "for meet break" << std::endl;
            break;
        }

    }
    Vm::top = savedEnv;
    std::cout << "结束 for 循环" << std::endl;
    return 0;
}