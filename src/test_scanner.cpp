#include <iostream>

#include "test_scanner.hpp"
#include "scanner.hpp"
#include "Token.hpp"

void test_scanner()
{
    Token token = get_token();
    
    while (token.type != END_OF_FILE_TK)
    {
        print_token(token);
        std::cout << std::endl;
        token = get_token();
    }
}