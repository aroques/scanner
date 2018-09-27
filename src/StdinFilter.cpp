#include <iostream>

#include "StdinFilter.hpp"

/*
    Public
*/

bool StdinFilter::get(char &c)
{
    while (std::cin.get(c))
    {
        if (isspace(c))
        {
            if (c == '\n') { this->line_number++; }
            
            continue; // skip whitespace
        }

        break;
    }

    return 1;
}