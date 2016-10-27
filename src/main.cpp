#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "vm/Vm.h"

using namespace std;

int main(int argc, char** argv) {
    /*
    Lexer lexer;
    lexer.setFile(argv[1]);

    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
    cout << lexer.scan()->toString() << endl;
     */

    Lexer lexer;
    //语法分析
    Parser parser = Parser(&lexer);
    //执行语法树
    Vm vm = Vm(parser.getRoot());
    vm.execute();
    return 0;
}