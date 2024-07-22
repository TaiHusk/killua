#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum TokenType {
    TOKEN_UNKNOW,
    COMMENT,
    IDENTIFER,
    STRING,
    NUMBER,

    OPEN_CURLY_BRACKET, // {
    CLOSE_CURLY_BRACKET, // }
};

#endif // TOKEN_TYPE_H