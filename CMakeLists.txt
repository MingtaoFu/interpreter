cmake_minimum_required(VERSION 3.3)
project(compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/lexer/Tag.cpp src/lexer/Tag.h src/lexer/Token.cpp src/lexer/Token.h src/lexer/Num.cpp src/lexer/Num.h src/lexer/Word.cpp src/lexer/Word.h src/lexer/Lexer.cpp src/lexer/Lexer.h src/symbols/Env.cpp src/symbols/Env.h src/inter/Node.cpp src/inter/Node.h src/inter/Expr/Id.cpp src/inter/Expr/Id.h src/inter/Expr/Expr.cpp src/inter/Expr/Expr.h src/inter/Stmt.cpp src/inter/Stmt.h src/parser/Parser.cpp src/parser/Parser.h src/vm/Vm.cpp src/vm/Vm.h src/inter/Block.cpp src/inter/Block.h src/inter/Blank.cpp src/inter/Blank.h src/inter/If.cpp src/inter/If.h src/inter/Decl.cpp src/inter/Decl.h src/inter/Set.cpp src/inter/Set.h src/inter/Expr/Factor.cpp src/inter/Expr/Factor.h src/inter/Expr/Math.cpp src/inter/Expr/Math.h src/inter/Expr/Rel.cpp src/inter/Expr/Rel.h src/inter/Expr/Equality.cpp src/inter/Expr/Equality.h src/inter/Expr/Unary.cpp src/inter/Expr/Unary.h src/inter/Expr/Term.cpp src/inter/Expr/Term.h src/inter/Expr/SelfOp.cpp src/inter/Expr/SelfOp.h src/inter/Init.cpp src/inter/Init.h)
add_executable(compiler ${SOURCE_FILES})