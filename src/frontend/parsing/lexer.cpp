#include "lexer.hpp"

Lexer::Lexer() {
    this->line = 1;
    this->current = 0;
}

std::vector<Token> Lexer::lexer(const std::vector<std::string> &text) {
    this->text = text;

    for (size_t it_line = 0; it_line < text.size(); it_line++) {
        const std::string &text_line = getLine();

        while (isNext()) {
            scanToken(std::string{text_line[current]});
        }

        current = 0;
        line += 1;
    }

    return tokens;
}

bool Lexer::match(std::regex pattern, char symbol) {
    return std::regex_match(std::string(1, symbol), pattern);
}

bool Lexer::match(std::regex pattern, std::string symbol) {
    return std::regex_match(symbol, pattern);
}

bool Lexer::match_alphabet(char symbol) {
    return match(std::regex("[a-zA-Z]"), symbol);
}

bool Lexer::match_alphabet(const std::string &symbol) {
    return match(std::regex("^[a-zA-Z]$"), symbol);
}

bool Lexer::match_next_identifer(const std::string &symbol) {
    return match(std::regex("^[a-zA-Z0-9_]$"), symbol);
}

bool Lexer::match_number(char symbol) {
    return match(std::regex("[0-9]"), symbol);
}

void Lexer::scanToken(std::string symbol) {
    if (std::isspace(symbol[0])) {
        current++;
        return;
    } else  if (symbol[0] == '\n' || symbol[0] == '\r') {
        current = 0;
        line += 1;
        return;
    }

    std::optional<std::pair<std::string, TokenType>> out_token_type = std::smart_view::vector::find(TokenTypeKnowledge, std::function<bool(const std::pair<std::string, TokenType>&)>([&symbol](const std::pair<std::string, TokenType>& pair) {
        return pair.first == symbol;
    }));

    if (out_token_type) {
        const std::pair<std::string, TokenType> _pair = *out_token_type;
        inc_current();
        token_push(_pair.second, symbol);
    } else if (symbol == "/") {
        if (isNext() && nextPeek() == "/") {
            token_push(TokenType::COMMENT, getLine().substr(current));
            current = getLine().size();
            return;
        }
    } else if (match_alphabet(symbol)) {
        std::string identifer;

        while (isNext() && match_next_identifer(peek())) {
            identifer += peek();
            inc_current();
        }
        
        token_push(TokenType::IDENTIFER, identifer);
    } else if (symbol == "\"") {
        std::string literal = symbol;
        int currentBuffer = current;
        inc_current();

        while (isNext()) {
            literal += peek();

            if (peek() == "\"") {
                if (lastPeek(1) != "\\") {
                    token_push(TokenType::STRING, literal, currentBuffer);
                    break;
                }
            }

            else if (current == getLine().size() - 1) {
                SyntaxException::except(Token(TokenType::STRING, symbol, getLine(), current, line), "Unterminated string literal");
            }

            inc_current();
        }

        __CheckUnterminatedString__(literal, symbol);
        inc_current();
    } else {
        SyntaxException::except(Token(TokenType::TOKEN_UNKNOW, symbol, getLine(), current, line), "Undefined char");
    }
}

void Lexer::token_push(const TokenType type, const std::string lexem, const std::string code_line, int current, int line) {
    tokens.emplace_back(type, lexem, code_line, current, line);
}

void Lexer::token_push(const TokenType type, const std::string lexem, int current) {
    tokens.emplace_back(type, lexem, getLine(), current, line);
}

void Lexer::token_push(const TokenType type, const std::string lexem) {
    tokens.emplace_back(type, lexem, getLine(), current, line);
}

bool Lexer::isNext() {
    return current < getLine().size();
}

void Lexer::inc_current() {
    current += 1;
}

std::string Lexer::peek() {
    return std::string{getLine()[current]};
}

std::string Lexer::nextPeek() {
    return std::string{getLine()[current + 1]};
}

std::string Lexer::lastPeek(int last) {
    return std::string{getLine()[current - last]};
}

std::string Lexer::getLine() {
    return text.at(line - 1);
}

void Lexer::__CheckUnterminatedString__(std::string literal, std::string symbol) {
    if (literal[literal.size() - 2] == '\\' || literal.size() == 1) {
        SyntaxException::except(Token(TokenType::STRING, symbol, getLine(), current, line), "Unterminated string literal");
    }
}