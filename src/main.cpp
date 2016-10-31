#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "vm/Vm.h"

using namespace std;

int main(int argc, char** argv) {

//    Lexer lexer;
//    lexer.setFile(argv[1]);
//
//    for (int i = 0;i < 250;i++) {
//        cout << lexer.scan()->toString() << "  " << lexer.getLine() << endl;
//    }


    Lexer lexer;
    if(!lexer.setFile()) {
        std::cout << "当前目录没有 input.txt !" << std::endl;
        return 0;
    }
    //语法分析
    Parser parser = Parser(&lexer);
    parser.program();
    //执行语法树:
    Vm vm = Vm(parser.getRoot());
    vm.execute();
    return 0;
}