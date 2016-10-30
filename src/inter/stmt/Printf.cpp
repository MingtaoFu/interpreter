//
// Created by BluesJiang on 2016/10/28.
//

#include "Printf.h"

int Printf::execute() {

    std::cout << "正在执行 Printf \t行号: " << lineNumber << std::endl; ;

    for (int i = exprs.size()-1; i >= 0 ; --i) {
        exprs[i]->execute();
    }
    return 0;
}