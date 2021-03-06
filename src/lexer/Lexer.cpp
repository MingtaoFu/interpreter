//
// Created by mingtao on 10/25/16.
//


#include "Lexer.h"
#include "Tag.h"
#include "Num.h"
#include <iostream>

bool isalpha2(char c) {
    ///
    /// 判断为字母或下划线
    ///
    if(c == '_' || isalpha(c)) {
        return true;
    }
    return false;
}

void Lexer::reserve(Word * word) {
    words.insert(std::pair<std::string, Word>(word->lexeme, *word));
}

int Lexer::line = 1;

void Lexer::lineIncre() {
    line ++;
}


int Lexer::getLine() {
    return line;
}

Lexer::Lexer() {
    reserve(new Word("if", Tag::IF));
    reserve(new Word("else", Tag::ELSE));
    reserve(new Word("while", Tag::WHILE));
    reserve(new Word("for", Tag::FOR));
    reserve(new Word("do", Tag::DO));
    reserve(new Word("break", Tag::BREAK));
    reserve(new Word("int", Tag::INT));
    reserve(new Word("printf", Tag::PRINTF));
}

bool Lexer::setFile() {
    input_file.open("input.txt");
    if(!input_file.is_open()) {
        return false;
    }
    read(buffer);
    return true;
}

void Lexer::read(char* ch) {
    input_file.read(ch, Lexer::BUFFER_LENTHGH);
    ch[input_file.gcount()] = '\0';
}

Token * Lexer::firstScan() {
    static bool isFirst = true;
    if(isFirst) {
        Word * word = new Word("{", Tag::L_BRACE);
        isFirst = false;
        return word;
    } else {
        return NULL;
    }
}

Token * Lexer::lastScan() {
    static bool isLast = true;
    if(isLast) {
        Word * word = new Word("}", Tag::R_BRACE);
        return word;
    } else {
        return NULL;
    }
}


///
/// 从缓冲区中\n
/// 首先跳过空白和注释\n
/// 然后检查是否发现特殊符号\n
/// 接着检查保留字的出现情况\n
/// 返回相应的 token\n
///


Token * Lexer::scan() {

    Token * token1 = firstScan();
    if(token1) return token1;

    while (1) {
        readch();
        if (peek == ' ' || peek == '\t' || peek == '\r') {
            continue;
        } else if (peek == '\n') {
            Lexer::lineIncre();
        } else if (peek == '/')  {
            if (readch('/')) {
                while (1) {
                    readch();
                    if (peek == '\n') {
                        Lexer::lineIncre();
                        break;
                    }
                }
            } else if (readch('*')) {
                while (1) {
                    readch();
                    if (peek == '*' && readch('/')) {
                        break;
                    } else if (peek == '\n') {
                        Lexer::lineIncre();
                    }
                }
            } else break;

        } else if (peek == '"') {
            while (1) {
                readch();
                if (peek =='\\') {
                    readch();
                    continue;
                }
                if (peek == '"') {
                    break;
                }
            }
        } else {
            break;
        }
    }

    Word *word;
    Token *token;
    //  分析特殊的符号
    switch (peek) {
        case '=':
            if(readch('=')) {
                word = new Word("==", Tag::EQ);
                return word;
            } else {
                token = new Token('=');
                return token;
            }
        case '!':
            if(readch('=')) {
                word = new Word("!=", Tag::NE);
                return word;
            }
        case ';':
            word = new Word(";", Tag::Semicolon);
            return word;
        case '+':
            if(readch('+')) {
                word = new Word("++", Tag::INCRE);
            } else {
                word = new Word("+", Tag::PLUS);
            }
            return word;
        case '-':
            if(readch('-')) {
                word = new Word("--", Tag::DECRE);
            } else {
                word = new Word("-", Tag::SUB);
            }
            return word;
        case '*':
            word = new Word("*", Tag::MULT);
            return word;
        case '/':
            word = new Word("/", Tag::DIV);
            return word;
        case '{':
            word = new Word("{", Tag::L_BRACE);
            return word;
        case '}':
            word = new Word("}", Tag::R_BRACE);
            return word;
        case '(':
            word = new Word("(", Tag::L_PARENTHESE);
            return word;
        case ')':
            word = new Word(")", Tag::R_PARENTHESE);
            return word;
        case ',':
            word = new Word(",", Tag::COMMA);
            return word;
        case '<':
            if(readch('=')) {
                word = new Word("<=", Tag::LE);
            } else {
                word = new Word("<", Tag::LT);
            }
            return word;
        case '>':
            if(readch('=')) {
                word = new Word(">=", Tag::GE);
            } else {
                word = new Word(">", Tag::GT);
            }
            return word;
        default:
            break;
    }

    //  提取单词和数字

    if(isalpha2(peek)) {
        std::string b;
        do {
            b.append(1, peek);

            readch();
        } while (isdigit(peek) || isalpha2(peek));

        index--;

        std::map<std::string, Word>::iterator iterator = words.find(b);
        if(iterator != words.end()) {
            return &iterator->second;
        }

        if (b.compare("printf") == 0) {
            word = new Word(b, Tag::PRINTF);
        } else {
            word = new Word(b, Tag::ID);
        }
        words.insert( std::pair<std::string, Word>(b, *word) );
        return word;

    } else if(isdigit(peek)) {
        int value = 0;
        do {
            value = 10 * value + (peek - '0');
            readch();
        } while (isdigit(peek));

        back();
        Num* num = new Num(value);
        return num;
    }

    Token * token2 = lastScan();
    return token2;
}


void Lexer::readch() {
    peek = buffer[index];
    index ++;
    if (index > Lexer::BUFFER_LENTHGH) {
        read(buffer);
        index = 1;
        peek = buffer[0];

    }
}

void Lexer::back() {
    index --;
}

bool Lexer::readch(char c) {
    char tmp = peek;
    readch();
    if(peek != c) {
        index --;
        peek = tmp;
        return false;
    }
    peek = ' ';
    return true;
}
