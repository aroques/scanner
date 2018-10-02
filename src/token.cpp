#include "Token.hpp"

#include <iostream>

void print_token(Token t)
{
    char format_str[100] = "%-10s %s\n";
    printf(format_str, "type:", std::to_string(t.type).c_str());
    printf(format_str, "instance:", t.instance.c_str());
    printf(format_str, "line no:", std::to_string(t.line_number).c_str());
}