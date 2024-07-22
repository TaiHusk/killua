#include "token.pair.hpp"

std::vector<std::pair<std::string, TokenType>> TokenTypeKnowledge = {
    std::pair{"{", TokenType::OPEN_CURLY_BRACKET},
    std::pair{"}", TokenType::CLOSE_CURLY_BRACKET},
};
