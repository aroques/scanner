#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

const int FINAL = 100;

enum TokenType
{
    OPERATOR_DELIMITER_TK = FINAL,
    IDENTIFIER_TK,
    NUMBER_TK,
    END_OF_FILE_TK
};

struct Token
{
    int type;
    std::string instance;
    int line_number;
};


#endif // !TOKEN_HPP