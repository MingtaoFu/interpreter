//
// Created by mingtao on 10/24/16.
//

#include "Token.h"

Token::Token(int t) {
    tag = t;
}

std::string Token::toString() {
    char ch = tag;
    std::string str = std::string().append(1, tag);
    return str;
}
