//
// Created by mingtao on 10/28/16.
//

#include "Var.h"
#include "../../vm/Vm.h"
#include "../error/VarNotInited.h"
#include "../error/VarNotFound.h"

Var::Var(Word * word): Factor(word) {
}

Constant* Var::execute() {
    std::string name = ((Word*)token)->lexeme;
    Id * id =  Vm::top->get(name);
    if(id) {
        this->id = id;
        return id->execute();
    }
    throw VarNotFound(name);
}
