//
// Created by mingtao on 10/28/16.
//

#include "Var.h"
#include "../../../vm/Vm.h"
#include "../../error/VarNotFound.h"

Var::Var(Word * word): Factor(word) {
}

int Var::execute() {
    std::string name = ((Word*)token)->lexeme;
    Id * id =  Vm::top->get(name);
    if(id) {
        this->id = id;
        Vm::printLine(lexline);
        return id->execute();
    }
    throw VarNotFound(name);
}

void Var::setValue(int value) {
    id->value = value;
}
