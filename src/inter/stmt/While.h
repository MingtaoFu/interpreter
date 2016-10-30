//
// Created by BluesJiang on 2016/10/29.
//

#ifndef COMPILER_WHILE_H
#define COMPILER_WHILE_H

#include "Stmt.h"
#include "../error/BreakError.h"
#include <iostream>

class While: public Stmt {
public:
    Expr* equality = NULL;
    Stmt* stmt = NULL;
    While(){};
    int execute() {
        std::cout << "执行While判断 \t行号: " << equality->lexline << std::endl;
        while (equality->execute() != 0){
            try {
                stmt->execute();
            }
            catch (BreakError aBreak) {
                std::cout << "while因break退出" << std::endl;
                break;
            }
            std::cout << "执行While判断 \t行号: " << equality->lexline << std::endl;
        }
        std::cout << "退出 While" << std::endl;
        return 0;
    };
};


#endif //COMPILER_WHILE_H
