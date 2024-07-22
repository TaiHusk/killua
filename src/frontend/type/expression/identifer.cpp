#include "identifer.hpp"

IDENTIFER_EXPRESSION_CLASS::IDENTIFER_EXPRESSION_CLASS(const Token& identifer): identifer(identifer) {
    _type = static_cast<decltype(ExpressionType::IDENTIFER)>(ExpressionType::IDENTIFER);
};