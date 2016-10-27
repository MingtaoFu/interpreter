//
// Created by mingtao on 10/26/16.
//

#include "Vm.h"

void Vm::execute() {

}

void Vm::setEntry(Node * node) {
    entry = node;
}

Vm::Vm(Node * node) {
    setEntry(node);
}
