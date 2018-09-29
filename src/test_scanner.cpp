#include <iostream>

#include "test_scanner.hpp"
#include "scanner.hpp"
#include "Token.hpp"

void test_scanner()
{
    Token token = get_token();
    
    while (token.type != END_OF_FILE_TK)
    {
        std::cout << token.instance << std::endl;
        token = get_token();
    }
    
}