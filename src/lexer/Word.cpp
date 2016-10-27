//
// Created by mingtao on 10/24/16.
//

#include "Word.h"

Word::Word(std::string s, int tag): Token(tag) {
    lexeme = s;
}

std::string Word::toString() {
    return lexeme;
}
