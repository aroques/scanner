#include <iostream>

#include "test_scanner.hpp"
#include "scanner.hpp"

void test_scanner()
{
    std::string token;
    
    while (get_token(token))
    {
        std::cout << token << std::endl;
    }
    
}