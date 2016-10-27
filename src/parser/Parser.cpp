//
// Created by mingtao on 10/25/16.
//

#include "Parser.h"
#include "../inter/expr/Equality.h"
#include "../inter/expr/SelfOp.h"
#include "../inter/expr/Term.h"
#include "../inter/stmt/Blank.h"
#include "../inter/stmt/If.h"
#include "../inter/stmt/Decl.h"

Parser::Parser(Lexer* lexer) {
    this->lexer = lexer;
    move();
}

Block * Parser::getRoot() {
    return root;
}

void Parser::move() {
    look = lexer->scan();
}

void Parser::error(std::string) {
}

void Parser::match(int t) {
    if(look->tag == t) {
        move();
    } else {
        error("syntax error");
    }
}

/**
 * 对块的解析
 */
Block * Parser::block() {
    Block * block = new  Block();

    match('{');
    Env * saveEnv = top;
    top = new Env(top);

    block->setEnv(top);

    Stmt * stmt1;
    stmt1 = stmt();

    while (stmt1 != NULL) {
        block->push_stmt(stmt1);
        stmt1 = stmt();
    }

    match('}');
    top = saveEnv;

    return block;
}

/**
 * 对声明的解析
 */
void Parser::decl() {
    /**
     * @TODO 一次声明多个变量 与 有初始化 的情况
     */

    match(Tag::INT);
    Token* t = look;
    match(Tag::ID);
    match(Tag::Semicolon);
    Id id( (Word *)t );
    top->put(*t, id);
}

Set * Parser::assign() {
    if(look->tag != Tag::ID) {
        return NULL;
    }

    Set * set1;

    Id * id = new Id((Word*)look);

    match(Tag::ID);
    match('=');

    Expr * equality1 = equality();
    set1 = new Set(id, equality1);
    match(';');

    return set1;
}

Expr * Parser::equality() {
    Expr * rel1 = rel();
    while(look->tag == Tag::EQ || look->tag == Tag::NE) {
        /**
         * 一个表达式最低优先级为 == !=
         * 可以没有这一项，若没有，直接返回rel对象
         *
         * @TODO 最低优先级其实还有其他
         */
        Token * token = look;
        move();
        rel1 = new Equality(token, rel1, rel());
    }
    return rel1;
}

Expr * Parser::rel() {
    Expr *expr1 = expr();
    switch (look->tag) {
        case '<':
        case '>':
        case Tag::LE:
        case Tag::GE: {

            Token * token = look;
            move();
            return new Rel(token, expr1, expr());
        }
        default:
            return expr1;
    }
}

Expr * Parser::expr() {
    Expr * expr1 = term();
    while (look->tag == '+' || look->tag == '-') {
        Token * token = look;
        move();
        expr1 = new Expr(token, expr1, term());
    }
    return expr1;
}

Expr * Parser::term() {
    Expr * expr1 = unary();
    while (look->tag == '*' || look->tag == '/') {
        Token * token = look;
        move();
        expr1 = new Term(token, expr1, unary());
    }
    return expr1;
}

Expr * Parser::unary() {
    switch (look -> tag) {
        case '-':
        case '+': {
            Token *token = look;
            move();
            return new Unary(token, selfop());
        }
        default:
            return selfop();
    }
}

Expr * Parser::selfop() {
    Expr * factor1 = factor();
    switch (look->tag) {
        case Tag::INCRE:
        case Tag::DECRE: {
            Token * token = look;
            move();
            return new SelfOp(token, factor1);
        }
        default:
            return factor1;
    }
}

Factor * Parser::factor() {
    switch(look->tag) {
        case Tag::NUM:
        case Tag::ID: {
            Factor * factor1 = new Factor(look);
            move();
            return factor1;
        }
        default:
            error("syntax error");
            return NULL;
    }
}

Stmt * Parser::stmt() {
    Expr * expr;
    Stmt * stmt1;
    //保存 break 外部的循环语句
    Stmt savedStmt;

    switch (look->tag) {
        case ';': {
            move();
            stmt1 = new Blank();
            break;
            //return Stmt::NULL;
        }
        case Tag::IF: {

            /**
             * @TODO
             */
            match(Tag::IF);
            match('(');
            expr = equality();
            match(')');

            Stmt * stmt2;
            if(look->tag == '{') {
                // if 后面跟的是一个块
                stmt2 = block();
            } else {
                // if 后面跟的是一个语句
                stmt2 = stmt();
            }

            If * _if = new If();
            _if->push_items(std::pair<Expr, Stmt>(*expr, *stmt2));
            stmt1 = _if;
        }
        case Tag::INT: {
            match(Tag::INT);
            //Factor * factor1 = factor();
            Token * token = look;
            match(Tag::ID);
            Id * id = new Id((Word*)token);
            if(look->tag == '=') {
                Expr * equality1 = equality();
            } else if(look->tag == ';'){
                match(';');
                stmt1 = new Decl(id);
            }
            return stmt1;
        }
        default:
            return assign();
    }

    return stmt1;
}

void Parser::program() {
    Block * stmt = block();
    root = stmt;
}