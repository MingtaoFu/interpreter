//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_BLANK_H
#define COMPILER_BLANK_H


#include "Stmt.h"

class Blank: public Stmt{
    // 未覆盖 stmt 默认的 execute
    // 反正 blank 也不会输出行号

};


#endif //COMPILER_BLANK_H
