//
// Created by mingtao on 10/26/16.
//

#include "Decl.h"
#include <iostream>

Decl::Decl(Id * id1) {
    id = id1;
}

void Decl::execute() {
    std::cout << "发生声明" << std::endl;
}