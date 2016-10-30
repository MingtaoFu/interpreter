//
// Created by mingtao on 10/28/16.
//

#include "Constant.h"
#include "../../../lexer/Num.h"

Constant::Constant(Token * token): Math(token, NULL, NULL){
}

int Constant::execute() {
    return ((Num*)this->op)->value;
}
