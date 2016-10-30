//
// Created by BluesJiang on 2016/10/30.
//

#include "Break.h"
#include "../../vm/Vm.h"

int Break::execute() {
    std::cout << "break \t\t行号: " << lexline << std::endl;
    Vm::printLine(lexline);
    BreakError r = BreakError("break");
    throw r;
}