//
// Created by mingtao on 10/24/16.
//

#ifndef COMPILER_WORD_H
#define COMPILER_WORD_H


#include "Token.h"
#include "Tag.h"

class Word: public Token {
public:
    std::string lexeme = "";
    Word(std::string s, int tag);
    std::string toString();
};


#endif //COMPILER_WORD_H
