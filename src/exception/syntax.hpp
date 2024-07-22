#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H

#include <iostream>
#include "../frontend/atomic/token.hpp"

class SyntaxException {
public:
    static void except(const Token& token, const std::string& message);
};

#endif // SYNTAX_EXCEPTION_H