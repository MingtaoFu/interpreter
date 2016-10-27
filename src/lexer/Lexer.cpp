//
// Created by mingtao on 10/25/16.
//

#include "Lexer.h"
#include "Tag.h"
#include <iostream>

void Lexer::reserve(Word word) {
    words.insert(std::pair<std::string, Word>(word.lexeme, word));
}

int Lexer::line = 1;

Lexer::Lexer() {
    this->line = 1;
}

void Lexer::setFile(std::string str) {
    file.open(str);
}

void Lexer::read(char* ch) {
    file.read(ch, 4096);
}

Token* Lexer::scan() {
    /**
     * 当前就读到了buffer[1]里
     * @TODO 双缓冲
     */
    char *buffer = buffers[buffer_index];

    if (buffer[0] == '\0') {
        read(buffer);
    }

    while (1) {
        readch();
        if (peek == ' ' || peek == '\t' || peek == '\r') {
            continue;
        } else if (peek == '\n') {
            Lexer::line++;
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

        word = new Word(b, Tag::ID);
        words.insert( std::pair<std::string, Word>(b, *word) );
        return word;

    } else if(isdigit(peek)) {
    }

    token = new Token(1);
    return token;
}

void Lexer::readch() {
    peek = buffers[buffer_index][index];
    index ++;
}

bool Lexer::readch(char c) {
    readch();
    if(peek != c) {
        index --;
        return false;
    }
    peek = ' ';
    return true;
}
