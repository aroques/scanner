#include <iostream>

#include "scanner.hpp"
#include "StdinFilter.hpp"

bool get_token(std::string &s)
{
    StdinFilter filter;

    char c;
    
    filter.get(c);

    if (std::cin.eof())
    {
        return 0;
    }

    std::string str(1, c);

    s = str;

    return 1;
}