#include "literal.hpp"

LITERAL_EXPRESSION_CLASS::LITERAL_EXPRESSION_CLASS(Token value, std::string formFactor): value(value), formFactor(formFactor) {
    _type = ExpressionType::LITERAL;
}