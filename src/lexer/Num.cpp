//
// Created by mingtao on 10/24/16.
//

#include "Num.h"

Num::Num(int v): Token(Tag::NUM) {
    value = v;
}

std::string Num::toString() {
    return "" + value;
}