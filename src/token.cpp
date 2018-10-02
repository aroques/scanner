#include "Token.hpp"

#include <iostream>

void print_token(Token t)
{
    char format_str[100] = "%-10s %s\n";
    printf(format_str, "type:", get_token_type(t.type).c_str());
    printf(format_str, "instance:", t.instance.c_str());
    printf(format_str, "line no:", std::to_string(t.line_number).c_str());
}

std::string get_token_type(int type)
{
    switch (type)
    {
        case OPERATOR_DELIMITER_TK: 
            return "operator/delimiter";

        case IDENTIFIER_TK:
            return "identifier";

        case NUMBER_TK:
            return "number";

        case END_OF_FILE_TK:
            return "EOF";
        
        default:
            return "token type not defined";
    }
}