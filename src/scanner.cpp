#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "scanner.hpp"
#include "container.hpp"
#include "Token.hpp"
#include "State.hpp"
#include "FSATable.hpp"

char get_next_char(int &line_number);

Token get_token()
{
    static int line_number = 1;

    char next_char = get_next_char(line_number);

    int state = 0, next_state;
    std::vector<std::array<int, NUM_COLUMNS>> table = get_FSA_table();
    std::string token_instance = "";

    std::array<int, 2> passive_states = {LEADING_WHITESPACE, INSIDE_COMMENT};

    while (state < FINAL) // not final state
    {
        next_state = table[state][col_idx(next_char)];
        if (next_state == ERROR)
        {
            std::cout << "scanner error: no token starts with the '" 
                + std::string(1, next_char) + "' character" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        if (next_state >= FINAL) break; // Final state
        else
        {
            // Not final state
            state = next_state;
            if (!item_in_list(state, passive_states)) 
            { 
                token_instance += next_char; 
            }            
            
            next_char = get_next_char(line_number);
        }
    }

    std::cin.unget();

    return Token {
        next_state,
        token_instance,
        line_number  
    };
}

char get_next_char(int &line_number)
{
    char c = EOF;
    
    std::cin.get(c);
    
    if (c == '\n') line_number++;
    
    return c;
}