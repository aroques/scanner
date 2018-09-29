#include <iostream>

#include "test_scanner.hpp"
#include "scanner.hpp"
#include "Token.hpp"

void test_scanner()
{
    Token token = get_token();
    
    int cnt = 0;
    while (cnt < 3)//(token.type != END_OF_FILE_TK)
    {
        std::cout << token.instance << std::endl;
        token = get_token();

        cnt++;
    }
    
}