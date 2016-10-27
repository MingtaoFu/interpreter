//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_VM_H
#define COMPILER_VM_H

#include "../inter/Block.h"

class Vm {
protected:
    Block * entry;

public:
    void execute();
    void setEntry(Block *);
    Vm(Block *);
};


#endif //COMPILER_VM_H
