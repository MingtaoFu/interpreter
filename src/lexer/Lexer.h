//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H


#include "Word.h"
#include <fstream>
#include <map>

class Lexer {
public:
    static void lineIncre();
    static void linePrint();
    static int getLine();
    void reserve(Word *);
    void setFile(std::string);
    void readch();
    void back();
    bool readch(char c);
    Token* scan();
    Lexer();


private:
    static const int BUFFER_LENTHGH = 4096;
    static int line;
    std::ifstream input_file;
    char buffer[4097];
    int buffer_index = 0;
    int index = 0;
    char peek = ' ';
    std::map<std::string, Word> words;
    void skipComments();
    void read(char*);
    Token * firstScan();
    Token * lastScan();
    bool readFinished = false;
};

#endif //COMPILER_LEXER_H
