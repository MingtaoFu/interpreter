//
// Created by mingtao on 10/26/16.
//

#include "Vm.h"
#include <string.h>

Env * Vm::top;
int Vm::currentLine = 0;
std::ofstream outputFile;

void Vm::printLine(int lineNumber) {
    // 判断是否进入的一行
    if (lineNumber != currentLine) {
        currentLine = lineNumber;
        char tmp [100];
        sprintf(tmp, "%d ", currentLine);
        std::cout << "VM 输出: " << currentLine << std::endl;
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
