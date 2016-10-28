//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include "../lexer/Lexer.h"
#include "../symbols/Env.h"
#include "../inter/Node.h"
#include "../inter/stmt/Stmt.h"
#include "../inter/stmt/Block.h"
#include "../inter/stmt/Set.h"
#include "../inter/expr/Factor.h"

class Parser {
private:
    Lexer * lexer;
    Token * look;

protected:
    Block * root;
    void move();
    void error(std::string);
    void match(int);

    Block * block();
    void decl();
    Set * assign();
    Stmt * stmt();
    Expr * equality();
    Expr * rel();
    Expr * expr();
    Expr * term();
    Expr * unary();
    Expr * selfop();
    Factor * factor();


public:
    Parser(Lexer* lexer);
    void program();
    Block * getRoot();
};


#endif //COMPILER_PARSER_H
