#ifndef INIZIALIZER_EXPRESSION_H
#define INIZIALIZER_EXPRESSION_H

#include <vector>
#include <memory>

#include "../../atomic/token.hpp"
#include "../expression.hpp"
#include "../expression.type.hpp"

class INIZIALIZER_EXPRESSION_CLASS: public Expression {
public:
    std::vector<Token> parentheses;
    std::unique_ptr<Expression> inizializer;
    std::vector<std::unique_ptr<Expression>> values;

    INIZIALIZER_EXPRESSION_CLASS() = default;
    INIZIALIZER_EXPRESSION_CLASS(const std::vector<Token>& parentheses, std::unique_ptr<Expression> inizializer, std::vector<std::unique_ptr<Expression>> values);
};

#endif // INIZIALIZER_EXPRESSION_H