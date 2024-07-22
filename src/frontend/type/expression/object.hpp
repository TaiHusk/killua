#ifndef OBJECT_EXPRESSION_H
#define OBJECT_EXPRESSION_H

#include <vector>
#include <memory>

#include "../../atomic/token.hpp"
#include "../expression.hpp"
#include "../expression.type.hpp"

class OBJECT_EXPRESSION_CLASS: public Expression {
public:
    std::vector<std::unique_ptr<Expression>> values;
    std::vector<Token> parentheses;

    OBJECT_EXPRESSION_CLASS() = default;
    OBJECT_EXPRESSION_CLASS(const std::vector<Token>& parentheses, std::vector<std::unique_ptr<Expression>> values);
};

#endif // OBJECT_EXPRESSION_H