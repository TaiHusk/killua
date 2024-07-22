#include "inizializer.hpp"

INIZIALIZER_EXPRESSION_CLASS::INIZIALIZER_EXPRESSION_CLASS(const std::vector<Token>& parentheses, std::unique_ptr<Expression> inizializer, std::vector<std::unique_ptr<Expression>> values)
 : parentheses(parentheses), inizializer(std::move(inizializer)), values(std::move(values)) {
    _type = ExpressionType::INIZIALIZER;
};