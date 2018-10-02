#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "scanner.hpp"
#include "container.hpp"
#include "Token.hpp"
#include "error.hpp"
#include "State.hpp"
#include "StdinFilter.hpp"
#include "FSATable.hpp"

Token get_token()
{
    StdinFilter filter;
    char next_char = filter.get_char();
    int state = 0, next_state;
    std::vector<std::array<int, NUM_COLUMNS>> table = get_FSA_table();
    std::string token_instance = "";

    std::array<int, 2> passive_states = {LEADING_WHITESPACE, INSIDE_COMMENT};

    while (state < FINAL) // not final state
    {
        next_state = table[state][col_idx(next_char)];

        if (next_state >= ERROR)
        {
            std::cout << "scanner error: " << get_error_reason(next_state, next_char) << std::endl;
            exit(EXIT_FAILURE);
        }
        
        if (next_state >= FINAL) { break; } // Final state
        else
        {
            // Not final state
            state = next_state;
            if (!item_in_list(state, passive_states)) 
            { 
                token_instance += next_char; 
            }            
            next_char = filter.get_char();
        }
    }

    std::cin.unget();

    return Token {
        next_state,
        token_instance,
        filter.line_number  
    };
}
