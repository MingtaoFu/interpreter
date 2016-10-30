//
// Created by mingtao on 10/28/16.
//

#include "Constant.h"
#include "../../../lexer/Num.h"
#include "../../../vm/Vm.h"

Constant::Constant(Token * token): Math(token, NULL, NULL){
}

int Constant::execute() {
    Vm::printLine(lexline);
    return ((Num*)this->op)->value;
}
