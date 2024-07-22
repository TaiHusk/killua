#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <regex>
#include <functional>
#include <string>
#include <optional>
#include <c++/29/experimental/smart_view>

#include "../atomic/token.hpp"
#include "../type/token.hpp"
#include "../type/token.pair.hpp"

#include "../../exception/syntax.hpp"

class Lexer {
public:
    Lexer();
    std::vector<std::string> text;
    std::vector<Token> tokens;
    std::vector<Token> lexer(const std::vector<std::string> &text);

private:
    int line;
    int current;
    bool match(std::regex pattern, char symbol);
    bool match(std::regex pattern, std::string symbol);
    bool match_alphabet(char symbol);
    bool match_alphabet(const std::string &symbol);
    bool match_number(char symbol);
    bool match_next_identifer(const std::string &symbol);

    void scanToken(std::string symbol);
    void token_push(const TokenType type, const std::string lexem, const std::string code_line, int current, int line);
    void token_push(const TokenType type, const std::string lexem, int current);
    void token_push(const TokenType type, const std::string lexem);

    bool isNext();
    void inc_current();
    std::string peek();
    std::string lastPeek(int last);
    std::string nextPeek();
    std::string getLine();

    void __CheckUnterminatedString__(std::string literal, std::string symbol);
};

#endif // LEXER_H