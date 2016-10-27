//
// Created by mingtao on 10/26/16.
//

#include "Vm.h"

void Vm::execute() {
    entry->execute();
}

void Vm::setEntry(Block * node) {
    entry = node;
}

Vm::Vm(Block * node) {
    setEntry(node);
}
