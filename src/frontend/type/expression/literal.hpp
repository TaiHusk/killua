#ifndef LITERAL_EXPRESSION_H
#define LITERAL_EXPRESSION_H

#include <vector>

#include "../../atomic/token.hpp"
#include "../expression.hpp"
#include "../expression.type.hpp"

class LITERAL_EXPRESSION_CLASS: public Expression {
public:
    Token value;
    std::string formFactor;

    LITERAL_EXPRESSION_CLASS() = default;
    LITERAL_EXPRESSION_CLASS(Token value, std::string formFactor);
};

#endif // LITERAL_EXPRESSION_H