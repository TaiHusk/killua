#ifndef IDENTIFER_EXPRESSION_H
#define IDENTIFER_EXPRESSION_H

#include "../../atomic/token.hpp"
#include "../expression.hpp"
#include "../expression.type.hpp"

class IDENTIFER_EXPRESSION_CLASS: public Expression {
public:
    Token identifer;
    
    IDENTIFER_EXPRESSION_CLASS() = default;
    IDENTIFER_EXPRESSION_CLASS(const Token& identifer);
};

#endif // IDENTIFER_EXPRESSION_H