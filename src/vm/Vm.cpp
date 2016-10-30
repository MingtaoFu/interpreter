//
// Created by mingtao on 10/26/16.
//

#include "Vm.h"

Env * Vm::top;
int Vm::currentLine = 0;

void Vm::printLine(int lineNumber) {
    if (lineNumber != currentLine) {
        currentLine = lineNumber;
        std::cout << "正在执行 行号:\t\t" << currentLine << std::endl;
    }
}

void Vm::execute() {
    entry->execute();
}

void Vm::setEntry(Block * node) {
    entry = node;
}

Vm::Vm(Block * node) {
    setEntry(node);
}
