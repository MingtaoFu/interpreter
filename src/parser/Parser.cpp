//
// Created by mingtao on 10/25/16.
//

#include <iostream>
#include "Parser.h"
#include "../inter/stmt/Blank.h"
#include "../inter/stmt/If.h"
#include "../inter/stmt/Decl.h"
#include "../inter/stmt/Printf.h"
#include "../inter/stmt/While.h"
#include "../inter/stmt/DoWhile.h"
#include "../inter/stmt/For.h"

#include "../inter/stmt/Break.h"

#include "../lexer/Num.h"
#include "SyntaxError.h"
#include "../inter/stmt/expr/Equality.h"
#include "../inter/stmt/expr/Term.h"
#include "../inter/stmt/expr/SelfOp.h"
#include "../inter/stmt/expr/Constant.h"
#include "../inter/stmt/expr/AddSub.h"
#include "../inter/stmt/expr/Comma.h"

Parser::Parser(Lexer* lexer) {
    this->lexer = lexer;
    move();
}

Block * Parser::getRoot() {
    return root;
}

void Parser::move() {
    look = lexer->scan();
    //在最后一个token会出现look为NULL
    if(look ) {
        look->line = Lexer::getLine();
    }

}

void Parser::error(std::string s) {
    throw SyntaxError(s);
}

void Parser::match(int t) {
    if(look->tag == t) {
        move();
    } else {
        std::cout <<"行号："<< look->line << std::endl;
        error("syntax error");
    }
}

/**
 * 对块的解析
 */
Block * Parser::block() {
    Block * block = new  Block();

    match('{');

    if(look->tag != '}') {

        Stmt * stmt1;

        while (look->tag != '}') {
            stmt1 = stmt();
            block->push_stmt(stmt1);
        }
    }

    match('}');

    return block;
}

/**
 * 对声明的解析
 */
void Parser::decl() {
    match(Tag::INT);
    match(Tag::ID);
    match(Tag::Semicolon);
}

Expr* Parser::comma() {
    Expr * expr1 = assign();
    while (look->tag == Tag::COMMA) {
        Token * token = look;
        move();
        expr1 = new Comma(token, expr1, assign());
    }
    return expr1;
}

Expr * Parser::assign() {
    Expr * equality1 = equality();
    while (look->tag == '=') {
        Token * token = look;
        move();
        equality1 = new Set(token, (Var*)equality1, assign());
    }
    return equality1;

}

Expr * Parser::equality() {
    Expr * rel1 = rel();
    while(look->tag == Tag::EQ || look->tag == Tag::NE) {
        /**
         *
         * 一个表达式最低优先级为 == !=
         * 可以没有这一项，若没有，直接返回rel对象
         *
         */
        Token * token = look;
        move();
        rel1 = new Equality(token, rel1, rel());
    }
    return rel1;
}

Expr * Parser::rel() {
    Expr *expr1 = addsub();
    switch (look->tag) {
        case '<':
        case '>':
        case Tag::LE:
        case Tag::GE: {

            Token * token = look;
            move();
            return new Rel(token, expr1, addsub());
        }
        default:
            return expr1;
    }
}

Expr * Parser::addsub() {
    Expr * expr1 = term();
    while (look->tag == '+' || look->tag == '-') {
        Token * token = look;
        move();
        expr1 = new AddSub(token, expr1, term());
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

Expr * Parser::factor() {
    switch(look->tag) {
        case Tag::NUM: {
            Token * token = look;
            move();
            return new Constant(token);
        }
        case Tag::ID: {
            Var * factor1 = new Var((Word*)look);
            factor1->lexline = look->line;
            move();
            return factor1;
        }
        default:
            std::cout <<"行号："<< look->line << std::endl;
            error("syntax error");
            return NULL;
    }
}

Stmt * Parser::stmt() {
    Expr * expr;
    Stmt * stmt1;
    //保存 break 外部的循环语句
    Stmt* savedStmt;

    switch (look->tag) {
        //  处理空语句
        case ';': {
            move();
            stmt1 = new Blank();
            break;
        }

        // 处理 block
        case '{':
            return block();

        // 处理分析 if 语句结构
        case Tag::IF: {
            If * _if;
            int line = look->line;
            match(Tag::IF);
            match('(');
            expr = comma();
            match(')');
            Token* token = look;
            Stmt * stmt2 = stmt();
            Stmt * stmt3 = NULL;
            if (token!= NULL && look == NULL) {
                int a;
            }

            if(look->tag == Tag::ELSE) {
                move();
                stmt3 = stmt();
            }

            _if = new If(expr, stmt2, stmt3);
            _if->lexline = line;

            stmt1 = _if;
            break;
        }

        // 处理分析 声明的语句结构
        case Tag::INT: {

            match(Tag::INT);

            stmt1 = new Decl();
            while (1) {
                Token * token = look;
                stmt1->lexline = look->line;
                match(Tag::ID);

                Var * var = new Var((Word*)token);
                Id * id = new Id((Word*)token);
                var->id = id;

                if(look->tag == '=') {
                    // 赋值情况
                    match('=');
                    Expr * expr1 = comma();
                    ((Decl*)stmt1)->put(var, expr1);
                } else {
                    // 不赋值情况
                    ((Decl*)stmt1)->put(var, NULL);
                }

                if(look->tag == ',') {
                    match(',');
                } else {
                    break;
                }
            }
            match(';');
            return stmt1;
        }

        // 处理 printf 函数结构
        case Tag::PRINTF: {
            match(Tag::PRINTF);
            match('(');
            Printf* tmp = new Printf();
            tmp->lexline = look->line;
            do {
                Token* token = look;

                if (look->tag == Tag::ID || look->tag == Tag::NUM) {
                    Expr* expr = Parser::assign();
                    tmp->exprs.push_back(expr);
                }
                if (look->tag == Tag::COMMA) {
                    match(',');
                }

            } while (look->tag != ')');
            match(')');
            match(';');
            stmt1 = tmp;
            return stmt1;
        }

        //  处理 while 循环语句结构
        case Tag::WHILE: {
            match(Tag::WHILE);
            While* whileLoop = new While();
            match('(');
            Expr* equal = comma();
            match(')');
            whileLoop->stmt = stmt();
            whileLoop->equality = equal;
            stmt1 = whileLoop;
            return stmt1;

        }

        // 处理 break 关键字
        case Tag::BREAK: {
            stmt1 = new Break();
            stmt1->lexline = look->line;
            match(Tag::BREAK);
            match(';');
            return stmt1;
        }

        //  处理 do while 循环语句结构
        case Tag::DO: {
            match(Tag::DO);
            DoWhile* doWhileLoop = new DoWhile();
            doWhileLoop->stmt = stmt();
            match(Tag::WHILE);
            match('(');
            doWhileLoop->expr = comma();
            match(')');
            match(';');
            stmt1 = doWhileLoop;
            return stmt1;
        }

        // 处理 for 循环语句结构
        case Tag::FOR: {
            For* forLoop = new For();
            forLoop->lexline = look->line;
            match(Tag::FOR);
            match('(');
            forLoop->initStmt = stmt();
            if (look->tag != ';') {
                forLoop->equal = comma();
            } else {
                forLoop->equal = new Constant(new Num(1));
                forLoop->equal->lexline = forLoop->lexline;
            }
            match(';');
            if (look->tag != ')') {
                forLoop->increasement = comma();
            } else {
                forLoop->increasement = new Blank();
            }
            match(')');
            forLoop->stmt = stmt();
            stmt1 = forLoop;
            return stmt1;

        }

        // 处理单行语句结构
        default:
            stmt1 = comma();
            stmt1->lexline = look->line;
            if (stmt1 != NULL){
                match(';');
            }
            return stmt1;
    }

    return stmt1;
}

void Parser::program() {
    Block * stmt = block();
    root = stmt;
}