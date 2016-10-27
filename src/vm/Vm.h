//
// Created by mingtao on 10/26/16.
//

#ifndef COMPILER_VM_H
#define COMPILER_VM_H

#include "../inter/Node.h"

class Vm {
protected:
    Node * entry;

public:
    void execute();
    void setEntry(Node *);
    Vm(Node *);
};


#endif //COMPILER_VM_H
