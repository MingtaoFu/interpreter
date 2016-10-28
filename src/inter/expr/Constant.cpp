//
// Created by mingtao on 10/28/16.
//

#include "Constant.h"
#include "../../lexer/Num.h"

Constant::Constant(Token * token){
}

Constant * Constant::execute() {
    return this;
}

int Constant::getValue() {
    return ((Num *)this->op)->value;
}
