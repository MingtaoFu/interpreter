//
// Created by BluesJiang on 2016/10/28.
//

#include "Printf.h"
#include "../../vm/Vm.h"

int Printf::execute() {

    std::cout << "正在执行 Printf \t行号: " << lexline << std::endl;
    Vm::printLine(lexline);

    for (int i = exprs.size()-1; i >= 0 ; --i) {
        exprs[i]->execute();
    }
    return 0;
}