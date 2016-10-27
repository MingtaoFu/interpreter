//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include "../lexer/Lexer.h"
#include "../symbols/Env.h"
#include "../inter/Stmt.h"
#include "../inter/Block.h"
#include "../inter/Node.h"
#include "../inter/Expr/Expr.h"
#include "../inter/Set.h"
#include "../inter/Expr/Rel.h"
#include "../inter/Expr/Factor.h"

class Parser {
private:
    Lexer * lexer;
    Token * look;

protected:
    Block * root;
    Env * top;
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
