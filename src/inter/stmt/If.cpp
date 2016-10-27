//
// Created by mingtao on 10/26/16.
//

#include "If.h"

void If::push_items(std::pair<Expr, Stmt> pair) {
    if_then->push_back(pair);
}
