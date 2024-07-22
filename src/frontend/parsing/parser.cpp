#include "parser.hpp"

Parser::Parser() {
    this->current = 0;
}

std::vector<std::unique_ptr<Expression>> Parser::parser(const std::vector<Token>& tokens) {
    this->tokens = tokens;

    this->ast.clear();
    this->current = 0;

    while (isNext()) {
        scanToken(peek());
    }

    return std::move(ast);
}

void Parser::scanToken(Token token) {
    if (isOpenPair(token)) {
        recursiveParse(token);
    } else if (token._type == TokenType::IDENTIFER) {
        auto commonExpression = std::make_unique<IDENTIFER_EXPRESSION_CLASS>(token);
        inc_current();
        expr_push(std::move(commonExpression));
    } else if (token._type == TokenType::STRING) {
        auto commonExpression = std::make_unique<LITERAL_EXPRESSION_CLASS>(token, ExpressionType::LITERALS.at("STRING"));
        inc_current();
        expr_push(std::move(commonExpression));
    } else {
        SyntaxException::except(token, std::format("Undefined expression: {0}", token.lexem));
    }
}

void Parser::inc_current() {
    this->current += 1;
}

void Parser::expr_push(std::unique_ptr<Expression> expression) {
    this->ast.push_back(std::move(expression));
}

void Parser::recursiveParse(Token token) {
    std::vector<Token> terms = walkToClosePair(token);
    Token close_pair = terms.back();

    if (!terms.empty()) {
        terms.erase(terms.begin());
        terms.pop_back();
    }

    std::unique_ptr<Expression> commonExpression;
    std::vector<std::unique_ptr<Expression>> nodes;

    std::tuple<std::vector<std::unique_ptr<Expression>>, int, int, std::vector<Token>> container_t = startRecursive();
    nodes = parser(terms);
    endRecursive(std::move(std::get<0>(container_t)), std::get<1>(container_t), std::get<2>(container_t), std::get<3>(container_t));

    auto previous_expr = getLastExpressionOfAST();

    if (token._type == TokenType::OPEN_CURLY_BRACKET) {
        if (previous_expr && std::smart_view::vector::includes({ExpressionType::IDENTIFER}, (*previous_expr)->_type)) {
            commonExpression = std::make_unique<INIZIALIZER_EXPRESSION_CLASS>(std::vector<Token>{token, close_pair}, std::move(*previous_expr), std::move(nodes));
            ast_pop();
        } else {
            commonExpression = std::make_unique<OBJECT_EXPRESSION_CLASS>(std::vector<Token>{token, close_pair}, std::move(nodes));
        }

        ast_pop();
    }

    expr_push(std::move(commonExpression));
};

std::tuple<std::vector<std::unique_ptr<Expression>>, int, int, std::vector<Token>> Parser::startRecursive() {
    return std::tuple<std::vector<std::unique_ptr<Expression>>, int, int, std::vector<Token>>{std::move(ast), current , tokens.size(), tokens};
};

void Parser::endRecursive(std::vector<std::unique_ptr<Expression>> bufferAST, int bufferIndex, int bufferSizeTokens, std::vector<Token> bufferTokens) {
    ast = std::move(bufferAST);
    current = bufferIndex;
    tokens = bufferTokens;
};

bool Parser::isOpenPair(Token token) {
    const std::vector<TokenType> open_pairs = {TokenType::OPEN_CURLY_BRACKET};

    return std::smart_view::vector::includes(open_pairs, std::function<bool(const TokenType&)>([&token](const TokenType& item) {
        return token._type == item;
    }));
}

std::vector<Token> Parser::walkToClosePair(Token token) {
    const TokenType saveOpenPair = token._type;
    const std::optional<TokenType> possibleClosePair = matchClosePair(token);
    std::vector<Token> terms;

    struct CounterPair {
        int open;
        int close;
    };

    terms.push_back(token);
    CounterPair counter = {.open = 1, .close = 0};
    current += 1;

    while (isNext()) {
        if (peek()._type == saveOpenPair) {
            counter.open++;
        } else if (peek()._type == possibleClosePair) {
            counter.close++;
        }

        if (counter.open == counter.close) {
            terms.push_back(peek());
            current++;
            break;
        }

        terms.push_back(peek());
        current++;
    }

    return terms;
}

std::optional<TokenType> Parser::matchClosePair(Token token) {
    if (token._type == TokenType::OPEN_CURLY_BRACKET) {
        return TokenType::CLOSE_CURLY_BRACKET;
    }

    return std::nullopt;
}

bool Parser::isNext() {
    return current < tokens.size();
}

std::optional<std::unique_ptr<Expression>> Parser::getLastExpressionOfAST() {
    if (ast.empty()) {
        return std::nullopt;
    }

    return std::move(ast.back());
}

Token Parser::peek() {
    return tokens[current];
}

void Parser::ast_pop() {
    if(!ast.empty()) {
        ast.pop_back();
    }
}