//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_VM_H
#define COMPILER_VM_H

#include "../inter/stmt/Block.h"
#include <iostream>
#include <fstream>

class Vm {
private:
    static int currentLine;

protected:
    Block * entry;

public:
    static Env * top;
    static void printLine(int lineNumber);
    void execute();
    void setEntry(Block *);
    Vm(Block *);
};


#endif //COMPILER_VM_H
