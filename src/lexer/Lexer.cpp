//
// Created by mingtao on 10/25/16.
//

#include "Lexer.h"
#include "Tag.h"
#include "Num.h"
#include <iostream>

void Lexer::reserve(Word * word) {
    words.insert(std::pair<std::string, Word>(word->lexeme, *word));
}

int Lexer::line = 1;

void Lexer::lineIncre() {
    line ++;
}

void Lexer::linePrint() {
    std::cout << line << "print" << std::endl;
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

void Lexer::setFile(std::string str) {
    input_file.open(str);
}

void Lexer::read(char* ch) {
    input_file.read(ch, Lexer::BUFFER_LENTHGH);
}

Token * Lexer::scan() {
    /**
     * 当前就读到了buffer[1]里
     * @TODO 双缓冲
     */

    if (buffer[0] == '\0') {
        read(buffer);
    }

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
            } else {
                break;
            }

        } else if (peek == '"') {
            while (1) {
                readch();
                if (peek != '\\' && readch('"')) {
                    break;
                }
            }
        } else {
            break;
        }
    }

    Word *word;
    Token *token;
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
        default:
            break;
    }

    /**
     * @TODO 判断下划线
     */
    if(isalpha(peek)) {
        std::string b;
        do {
            b.append(1, peek);

            readch();
        } while (isalnum(peek));

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

        return new Num(value);
    }
    return NULL;
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
