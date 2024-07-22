#ifndef TOKEN_H
#define TOKEN_H

#include <sstream>
#include <iostream>
#include "../type/token.hpp"

class Token {
public:
    Token() = default;

    TokenType _type;
    std::string lexem;
    std::string code_line;
    int current;
    int line;

    Token(const TokenType _type, const std::string lexem, const std::string code_line, int current, int line);

    friend std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << '(' << token._type << ", " << token.lexem << ')';
        return os;
    }
};

#endif // TOKEN_H