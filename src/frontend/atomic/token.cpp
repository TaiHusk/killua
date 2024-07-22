#include "./token.hpp"

Token::Token(const TokenType _type, const std::string lexem, const std::string code_line, int current, int line)
    : _type(_type), lexem(lexem), code_line(code_line), current(current), line(line) {};
