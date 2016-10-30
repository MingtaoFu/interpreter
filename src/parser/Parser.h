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
#include "../inter/stmt/expr/Set.h"

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
    Stmt * stmt();
    Expr * comma();
    Expr * assign();
    Expr * equality();
    Expr * rel();
    Expr * addsub();
    Expr * expr();
    Expr * term();
    Expr * unary();
    Expr * selfop();
    Expr * factor();



public:
    Parser(Lexer* lexer);
    void program();
    Block * getRoot();
};


#endif //COMPILER_PARSER_H
