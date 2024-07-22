#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "token.hpp"
#include "expression.type.hpp"

class Expression {
public:
    std::string _type;

    Expression() = default;
    virtual ~Expression() = default;
};

#endif // EXPRESSION_H