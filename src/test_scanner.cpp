#include <iostream>

#include "test_scanner.hpp"
#include "scanner.hpp"
#include "token.hpp"

void test_scanner()
{
    Token token;
    
    print_token_header();

    do 
    {       
        token = get_token();
        print_token(token);
    } 
    while (token.type != END_OF_FILE_TK);

}