#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "scanner.hpp"
#include "token.hpp"
#include "state.hpp"
#include "FSATable.hpp"

static char get_next_char();

Token get_token()
{
    static int line_number = 1;

    char next_char = get_next_char();

    int state = 0, next_state;
    bool state_is_active;
    std::vector<std::array<int, NUM_COLUMNS>> table = get_FSA_table();
    std::string token_instance = "";

    while (state < FINAL) // not final state
    {
        next_state = table[state][col_idx(next_char)];
        if (next_state == ERROR)
        {
            std::cout << "scanner error: no token starts with the '" 
                + std::string(1, next_char) + "' character. line: " 
                << line_number << std::endl;
            exit(EXIT_FAILURE);
        }
        
        if (next_state >= FINAL) break; // Final state
        else
        {
            // Not final state
            state = next_state;

            state_is_active = passive_states.count(state) == 0;
            if (state_is_active) 
                token_instance += next_char; 
            
            // if current char is \n, then increment line number
            if (next_char == '\n') line_number++;

            next_char = get_next_char();
        }
    }

    std::cin.unget(); // unget look-ahead

    return Token {
        get_token_type(next_state, token_instance),
        token_instance,
        line_number  
    };
}

static char get_next_char()
{
    char c = EOF;
    
    std::cin.get(c);
    
    return c;
}