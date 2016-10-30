//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

#include <string>

class Node {
protected:

    void error(std::string);

public:
    int lexline = 0;
    Node();
};


#endif //COMPILER_NODE_H
