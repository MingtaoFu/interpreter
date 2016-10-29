//
// Created by mingtao on 10/25/16.
//

#include <iostream>
#include "Parser.h"
#include "../inter/expr/Equality.h"
#include "../inter/expr/SelfOp.h"
#include "../inter/expr/Term.h"
#include "../inter/stmt/Blank.h"
#include "../inter/stmt/If.h"
#include "../inter/stmt/Decl.h"
#include "../inter/stmt/Printf.h"
#include "../lexer/Num.h"
#include "../inter/expr/Var.h"
#include "../inter/expr/Constant.h"
#include "SyntaxError.h"

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
    if(look) {
        look->line = Lexer::getLine();
    }
    /*
    try {
        std::cout<< ((Num*)look)->value<<" ssss" <<std::endl;
    } catch (std::runtime_error e) {

    }
     */
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

    Stmt * stmt1;
    stmt1 = stmt();

    while (stmt1 != NULL) {
        block->push_stmt(stmt1);
        stmt1 = stmt();
    }

    match('}');

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
    //Token* t = look;
    match(Tag::ID);
    match(Tag::Semicolon);
    //Id id( (Word *)t );
    //top->put(*t, id);
}

Set * Parser::assign() {
    if(look->tag != Tag::ID) {
        return NULL;
    }

    Set * set1;

    Var * var = new Var((Word*)look);

    match(Tag::ID);
    match('=');

    Expr * equality1 = equality();
    set1 = new Set(var, equality1);
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
    //std::cout << ((Num*)look)->value << std::endl;
    while (look->tag == '+' || look->tag == '-') {
        Token * token = look;
        move();
        expr1 = new Expr(token, expr1, term());
        //std::cout << "分析出了+/-" << std::endl;
    }
    return expr1;
}

Expr * Parser::term() {
    Expr * expr1 = unary();
    while (look->tag == '*' || look->tag == '/') {
        Token * token = look;
        move();
        expr1 = new Term(token, expr1, unary());
        //std::cout << "分析出了乘除" << std::endl;
    }
    return expr1;
}

Expr * Parser::unary() {
    switch (look -> tag) {
        case '-':
        case '+': {
            Token *token = look;
            move();
            std::cout << "分析出了正负" << std::endl;
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
            std::cout << "分析出了++/--" << std::endl;
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
            //std::cout << "构建整数常量：" << ((Num*)token)->value <<std::endl;
            return new Constant(token);
        }
        case Tag::ID: {
            Var * factor1 = new Var((Word*)look);
                    /*
            Factor * factor1 = new Factor(look);
                     */
            move();
            std::cout << "分析出了因子" << std::endl;
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
        case '{':
            return block();
        case Tag::IF: {
            If * _if;

            /**
             * @TODO
             */
            match(Tag::IF);
            match('(');
            expr = equality();
            match(')');

            Stmt * stmt2 = stmt();
            Stmt * stmt3 = NULL;

            /*
            if(look->tag == '{') {
                // if 后面跟的是一个块
                stmt2 = block();
            } else {
                // if 后面跟的是一个语句
                stmt2 = stmt();
            }
             */

            if(look->tag == Tag::ELSE) {
                move();
                stmt3 = stmt();
            }

            _if = new If(expr, stmt2, stmt3);

            /*
            _if->push_items(std::pair<Expr, Stmt>(expr, stmt2));

            //有多个，考虑吧if变成while
            while (look->tag == Tag::ELSE) {
                move();
                if(look->tag == Tag::IF) {
                    match('(');
                    expr = equality();
                    match(')');
                    if(look->tag == '{') {
                        // if 后面跟的是一个块
                        stmt2 = block();
                    } else {
                        // if 后面跟的是一个语句
                        stmt2 = stmt();
                    }
                    _if->push_items(std::pair<Expr, Stmt>(expr, stmt2));
                } else {
                    if(look->tag == '{') {
                        // if 后面跟的是一个块
                        stmt2 = block();
                    } else {
                        // if 后面跟的是一个语句
                        stmt2 = stmt();
                    }
                    _if->push_items(std::pair<Expr, Stmt>(Num(1), stmt2));
                    break;
                }
            }
             */

            stmt1 = _if;
            break;
        }
        case Tag::INT: {
            match(Tag::INT);
            //Factor * factor1 = factor();
            Token * token = look;
            match(Tag::ID);
            Var * var = new Var((Word*)token);
            Id * id = new Id((Word*)token);
            var->id = id;
            if(look->tag == '=') {
                Expr * equality1 = equality();
            } else if(look->tag == ';'){
                match(';');
                stmt1 = new Decl(var);
            }
            return stmt1;
        }

        case Tag::PRINTF: {
            match(Tag::PRINTF);
            match('(');
            Printf* tmp = new Printf();
            do {
                Token* token = look;


//                if (look->tag == Tag::ID) {
//                    match(Tag::ID);
//                    if (look->tag == Tag::COMMA) {
//                        Var* var = new Var((Word*) token);
//                        tmp->vars.push_back(var);
//                    } else {
//                        Expr* expr = Parser::expr();
//                        tmp->exprs.push_back(expr);
//                    }
//                } else if (look->tag == Tag::NUM) {
//                    Expr* expr = Parser::expr();
//                    tmp->exprs.push_back(expr);
//                }
                if (look->tag == Tag::ID || look->tag == Tag::NUM) {
                    Expr* expr = Parser::expr();
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
        default:
            return assign();
    }

    return stmt1;
}

void Parser::program() {
    Block * stmt = block();
    root = stmt;
}