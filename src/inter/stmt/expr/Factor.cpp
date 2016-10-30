//
// Created by mingtao on 10/26/16.
//

#include "Factor.h"

Factor::Factor(Token * token1): Math(token1, NULL, NULL) {
    token = token1;
}

/*
Constant * Factor::execute() {
    // 在此从作用域中获得
    Word * d = (Word*)token;
    std::string name = ((Word*)token)->lexeme;
    Id * _id = Vm::top->get(name);

    id = _id;

    if(id) {
        if(id->value != NULL) {
            return id->value;
        }
        throw VarNotInited(name);
    }
    throw VarNotFound(name);
}
 */
