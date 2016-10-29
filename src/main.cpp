#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "vm/Vm.h"

using namespace std;

int main(int argc, char** argv) {

    Lexer lexer;
    lexer.setFile(argv[1]);

    for (int i = 0;i < 76;i++) {
        cout << lexer.scan()->toString() << endl;
    }

//
//    Lexer lexer;
//    lexer.setFile(argv[1]);
//    cout << argv[1] << endl;
//    //语法分析
//    Parser parser = Parser(&lexer);
//    parser.program();
//    //执行语法树:
//    Vm vm = Vm(parser.getRoot());
//    vm.execute();
    return 0;
}