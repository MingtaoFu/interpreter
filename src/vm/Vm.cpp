//
// Created by mingtao on 10/26/16.
//

#include "Vm.h"
#include <string.h>

Env * Vm::top;
int Vm::currentLine = 0;
std::ofstream outputFile;

void Vm::printLine(int lineNumber) {
    if (lineNumber != currentLine) {
        currentLine = lineNumber;
//        std::cout << "正在执行 行号:\t\t" << currentLine << std::endl;
        char tmp [1000];
        sprintf(tmp, "%d ", currentLine);
        outputFile.write(tmp, strlen(tmp));
    }
}

void Vm::execute() {
    entry->execute();
}

void Vm::setEntry(Block * node) {
    entry = node;
}

Vm::Vm(Block * node) {
    outputFile = std::ofstream();
    outputFile.open("output.txt");
    setEntry(node);
}
