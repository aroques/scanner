#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "scanner.hpp"
#include "StdinFilter.hpp"
#include "FSATable.hpp"
#include "Token.hpp"
#include "Error.hpp"

Token get_token()
{
    StdinFilter filter;
    char next_char = filter.get_char();
    int state = 0, next_state;
    std::vector<std::array<int, NUM_COLUMNS>> table = get_FSA_table();
    std::string token_instance = "";

    while (state < FINAL) // not final state
    {
        next_state = table[state][col_idx(next_char)];

        if (next_state >= ERROR)
        {
            std::cout << "scanner error" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        if (next_state >= FINAL)
        {
            // Final state
            // TBD: Add logic for keyword tokens
            return Token {
                next_state,
                token_instance,
                filter.line_number  
            };
        }
        else
        {
            // Not final state
            state = next_state;
            token_instance += next_char;
            next_char = filter.get_char();
        }
    }
    return Token {
        -1,
        "",
        -1  
    };
}