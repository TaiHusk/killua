#include "syntax.hpp"

void SyntaxException::except(const Token& token, const std::string& message) {
    std::cerr << "\033[1;31mException\033[0m: " << message << '\n';
    std::exit(1);
}