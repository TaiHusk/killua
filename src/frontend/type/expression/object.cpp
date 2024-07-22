#include "object.hpp"

OBJECT_EXPRESSION_CLASS::OBJECT_EXPRESSION_CLASS(const std::vector<Token>& parentheses, std::vector<std::unique_ptr<Expression>> values)
 : parentheses(parentheses), values(std::move(values)) {
    _type = ExpressionType::OBJECT;
};