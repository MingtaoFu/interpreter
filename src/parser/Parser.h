//
// Created by mingtao on 10/25/16.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include "../lexer/Lexer.h"
#include "../symbols/Env.h"
#include "../inter/Node.h"
#include "../inter/stmt/Stmt.h"
#include "../inter/stmt/Block.h"
#include "../inter/stmt/expr/Set.h"

///
/// \brief 语法分析类
///
/// 用于构建抽象语法树,
/// 以便虚拟机去执行
///
///

class Parser {
private:
    Lexer * lexer;
    Token * look;

protected:
    Block * root; ///< 语法树的根节点
    /// 扫描的 token 前移
    void move();
    /// 抛出错误
    void error(std::string);
    /// 根据语法匹配关键 token
    void match(int);

    /// 生成 块 对象
    Block * block();
    /// 完成声明语句
    void decl();
    /// 生成 语句 对象
    Stmt * stmt();
    /// 生成 逗号表达式 对象
    Expr * comma();
    /// 生成 赋值表达式 对象
    Expr * assign();
    /// 生成 等于表达式 对象
    Expr * equality();
    /// 生成 打小于表达式 对象
    Expr * rel();
    /// 生成 加减表达式 对象
    Expr * addsub();
    /// 生成 表达式项 对象
    Expr * term();
    /// 生成 符号表达式 对象
    Expr * unary();
    /// 生成 自增自减表达式 对象
    Expr * selfop();
    /// 生成 因子 对象
    Expr * factor();



public:

    /// \param lexer : 语法分析器对象
    Parser(Lexer* lexer);
    /// 分析函数入口
    void program();
    /// 获取语法树的根节点
    Block * getRoot();
};


#endif //COMPILER_PARSER_H
