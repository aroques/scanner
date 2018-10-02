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

void print_token_header();
void print_token(Token t);
std::string get_token_type(int type);

#endif // !TOKEN_HPP