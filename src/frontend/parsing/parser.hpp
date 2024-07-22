#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <regex>
#include <functional>
#include <string>
#include <optional>
#include <format>
#include <memory>
#include <tuple>

#include <c++/29/experimental/smart_view>

#include "../atomic/token.hpp"
#include "../type/token.hpp"
#include "../type/token.pair.hpp"
#include "../type/expression.hpp"
#include "../type/expression.type.hpp"

#include "../type/expression/identifer.hpp"
#include "../type/expression/literal.hpp"
#include "../type/expression/object.hpp"
#include "../type/expression/inizializer.hpp"

#include "../../exception/syntax.hpp"

class Parser {
public:
    Parser();
    std::vector<Token> tokens;
    std::vector<std::unique_ptr<Expression>> parser(const std::vector<Token>& tokens);

private:
    std::vector<std::unique_ptr<Expression>> ast;
    int current;

    void scanToken(Token token);
    void expr_push(std::unique_ptr<Expression> expression);
    void inc_current();
    void recursiveParse(Token token);
    std::tuple<std::vector<std::unique_ptr<Expression>>, int, int, std::vector<Token>> startRecursive();
    void endRecursive(std::vector<std::unique_ptr<Expression>> bufferAST, int bufferIndex, int bufferSizeTokens, std::vector<Token> bufferTokens);
    bool isOpenPair(Token token);
    std::vector<Token> walkToClosePair(Token token);
    std::optional<TokenType> matchClosePair(Token token);
    bool isNext();
    Token peek();
    std::optional<std::unique_ptr<Expression>> getLastExpressionOfAST();
    void ast_pop();
};

#endif // PARSER_H