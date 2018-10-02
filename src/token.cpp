#include "Token.hpp"

#include <iostream>

static char format_str[100] = "%-20s %-10s %-2s\n";

void print_token_header()
{
    printf(format_str, "Type", "Instance", "Line No");
    for (int i = 0; i < 39; i++) printf("-");
    printf("\n");
}

void print_token(Token t)
{
    printf(format_str, get_token_type(t.type).c_str(),
        t.instance.c_str(), std::to_string(t.line_number).c_str());
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