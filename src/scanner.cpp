#include <iostream>

#include "scanner.hpp"

void print_stdin()
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

        std::cout << c << std::endl; 
    }

    std::cout << line_count << std::endl;
}