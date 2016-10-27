//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILE_TOKEN_H
#define COMPILE_TOKEN_H

#include <string>

class Token {

public:
    int tag;
    Token(int t);
    virtual std::string toString();
    inline bool operator < (const Token t) const {
        return this->tag < t.tag;
    }
};


#endif //COMPILE_TOKEN_H
