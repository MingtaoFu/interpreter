//
// Created by mingtao on 10/25/16.
//

#include "Node.h"
#include "../lexer/Lexer.h"

void Node::error(std::string) {
}

Node::Node() {
    lexline = Lexer::line;
}
