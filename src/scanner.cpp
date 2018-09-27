#include <iostream>

#include "scanner.hpp"

bool get_token(std::string &s)
{
    int line_count = 1;

    char c;
    
    while (std::cin.get(c))
    {
        if (isspace(c))
        {
            if (c == '\n') { line_count++; }
            
            continue; // skip whitespace
        }

        break; 
    }

    if (std::cin.eof())
    {
        return 0;
    }

    std::string str(1, c);

    s = str;

    return 1;
}