//
// Created by mingtao on 10/25/16.
//

#include "Id.h"
#include "../../vm/Vm.h"
#include "../error/VarNotFound.h"
#include "../error/VarNotInited.h"

Id::Id(Word * word): Factor(word) {
}

Constant * Id::execute() {
    if(id->value != NULL) {
        return id->value;
    } else {
        throw VarNotInited(((Word*)id->token)->lexeme);
    }
}
