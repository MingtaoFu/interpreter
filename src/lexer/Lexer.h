//
// Created by mingtao on 10/25/16.
//


#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H


#include "Word.h"
#include <fstream>
#include <map>

///
/// \brief Class Lexer 词法分析器
///
/// 该类用于把源文件分析成token流,
/// 便于语法分析时对元素的提取
///
class Lexer {
public:
    static void lineIncre();
    /// 获取 token 行号
    static int getLine();
    /// 录入保留字
    void reserve(Word *);
    ///  设置源文件
    bool setFile();
    /// 获取下一个字符
    void readch();
    /// \brief look ahead 方法
    ///
    /// \param c 判断下一个字符是否为c
    bool readch(char c);
    /// 字符回退
    void back();
    /// 扫描下一个 token
    Token* scan();
    /// 构造Lexer 初始化保留字
    Lexer();


private:
    static const int BUFFER_LENTHGH = 4096;     ///< 读取文件的缓冲区大小
    static int line;    ///< 当前行
    std::ifstream input_file;   ///< 输入文件
    char buffer[4097];  ///< 缓冲区
    int index = 0;  ///< 缓冲区读取指针
    char peek = ' ';    ///< 当前扫描到的字符
    std::map<std::string, Word> words;  ///< 单词保留区
    void read(char*);   ///< 读取文件进入buffer中
    /// 构建根块
    Token * firstScan();
    /// 构建根块
    Token * lastScan();
    bool readFinished = false; ///< 标记是否到达文件末尾
};

#endif //COMPILER_LEXER_H
