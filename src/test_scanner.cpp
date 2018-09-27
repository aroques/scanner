#include <iostream>

#include "test_scanner.hpp"

void print_stdin()
{
    char c;
    int line_count = 1;
    while (std::cin.get(c))
    {
        if (isspace(c))
        {
            if (c == '\n') { line_count++; }
            
            continue;
        }

        std::cout << c << std::endl; 
    }

    std::cout << line_count << std::endl;
}