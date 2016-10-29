//
// Created by BluesJiang on 2016/10/28.
//

#include "Printf.h"

void Printf::execute() {

    std::cout << "正在执行 Printf 有参数: " ;
    std::cout << std::endl << "exprs:\n";

    for (int i = exprs.size()-1; i >= 0 ; --i) {
        std::cout << "执行: " << exprs[i] << "\n" ;
        exprs[i]->execute();
        std::cout << std::endl;
    }

}