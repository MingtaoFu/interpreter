//
// Created by mingtao on 10/25/16.
//

#include "Id.h"
#include "../../vm/Vm.h"
#include "../error/VarNotFound.h"
#include "../error/VarNotInited.h"

Id::Id(Word * word): Factor(word) {
}

int Id::execute() {
    return this->value;
}
