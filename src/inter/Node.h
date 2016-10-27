//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

#include <string>

class Node {
protected:
    int lexline = 0;
    void error(std::string);

public:
    Node();
};


#endif //COMPILER_NODE_H
