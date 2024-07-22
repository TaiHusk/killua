#ifndef EXPRESSION_TYPE_H
#define EXPRESSION_TYPE_H

#include <string>
#include <map>

class ExpressionType {
public:
    static constexpr std::string conv(const std::string& type) {
        return type + "Expression";
    }

    static inline const std::map<std::string, std::string> SUPER_TYPE = {
        {"STRING", conv("SuperString")},
        {"NUMBER", conv("SuperNumber")}
    };

    static inline const std::map<std::string, std::string> LITERALS = {
        {"NUMBER", conv("NumberLiteral")},
        {"STRING", conv("StringLiteral")},
        {"BOOLEAN", conv("BooleanLiteral")}
    };

    static inline const std::string INSTRUCTION = "INSTRUCTION";
    static inline const std::string ARGUMENTS = conv("ArgumentsClause");
    static inline const std::string TYPE_OF_ARGUMENT = conv("TypeArgument");
    static inline const std::string ATTRIBUTES = conv("Attributes");
    static inline const std::string ASSIGNMENT = conv("Assignment");
    static inline const std::string INIZIALIZER = conv("Initializer");
    static inline const std::string PROPERTY = conv("Property");
    static inline const std::string GENERICS = conv("Generics");
    static inline const std::string PARENTHESIS = conv("Parenthesis");
    static inline const std::string ARRAY = conv("Array");
    static inline const std::string TYPE_OF_ARRAY = conv("TypeArray");
    static inline const std::string OBJECT = conv("Object");
    static inline const std::string CALL = conv("Call");
    static inline const std::string MEMBER = conv("Member");
    static inline const std::string LITERAL = conv("Literal");
    static inline const std::string IDENTIFER = conv("Identifer");
};

#endif // EXPRESSION_TYPE_H