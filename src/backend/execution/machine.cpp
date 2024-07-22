#include "machine.hpp"

Machine::Machine() {
    this->current = 0;
}

void Machine::launcher(std::vector<std::unique_ptr<Expression>> ast) {
    this->ast = std::move(ast);

    while (isNext()) {
        scanExpression(peek());
        current++;
    }
}

void Machine::scanExpression(const Expression& expression) {
    if (expression._type == ExpressionType::INIZIALIZER) {
        const INIZIALIZER_EXPRESSION_CLASS* inizializerMajorExpression = std::reflect::construct<INIZIALIZER_EXPRESSION_CLASS>(expression);

        if (inizializerMajorExpression != nullptr) {
            const Expression* inizializer = std::reflect::construct<Expression>(inizializerMajorExpression->inizializer);
            std::string enviroment_string_type;
            LuminousCommandEnvironmentCosmos enviroment_t;

            if (inizializer->_type != ExpressionType::IDENTIFER) {
                std::string message = "Expected an identifier. Please check the syntax and try again.";
                SyntaxException::except(Token(TokenType::TOKEN_UNKNOW, "", "", 0, 0), message);
            } else {
                const IDENTIFER_EXPRESSION_CLASS* identifer = std::reflect::construct<IDENTIFER_EXPRESSION_CLASS>(inizializerMajorExpression->inizializer);
                
                enviroment_string_type = identifer->identifer.lexem;

                if (std::smart_view::vector::includes(LuminousCommandEnvironmentCatalogue, enviroment_string_type) == false) {
                    std::string message = "Unknown environment/command";
                    SyntaxException::except(Token(TokenType::TOKEN_UNKNOW, "", "", 0, 0), message);
                }

                enviroment_t = LuminousCommandEnvironmentScanner(enviroment_string_type);
            }

            if (enviroment_t == LuminousCommandEnvironmentCosmos::shell) {
                for (const auto& _value : inizializerMajorExpression->values) {
                    if (_value->_type != ExpressionType::LITERAL) {
                        std::string message = "Argument must be a string literal. ";
                        message += "The given argument is not a valid string literal.";
                        SyntaxException::except(Token(TokenType::TOKEN_UNKNOW, "", "", 0, 0), message);
                    } else {
                        const LITERAL_EXPRESSION_CLASS* literal = std::reflect::construct<LITERAL_EXPRESSION_CLASS>(_value);

                        if (literal->formFactor != ExpressionType::LITERALS.at("STRING")) {
                            std::string message = "Argument must be a string literal. ";
                            message += "The given argument is not a valid string literal.";
                            SyntaxException::except(Token(TokenType::TOKEN_UNKNOW, "", "", 0, 0), message);
                        } else {
                            std::string command = literal->value.lexem.substr(1, literal->value.lexem.size() - 2);
                            system(command.c_str());
                        }
                    }
                }
            }
        }
    } else {
        SyntaxException::except(Token(), "Unexpected expression");
    }
}

Expression& Machine::peek() {
    return *ast[current];
}

void Machine::inc_current() {
    this->current += 1;
}

bool Machine::isNext() {
    return current < ast.size();
}