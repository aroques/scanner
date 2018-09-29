#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "scanner.hpp"
#include "StdinFilter.hpp"
#include "FSATable.hpp"

enum Column {OP_DELIM, LETTER, NUMBER, EOF_CHAR, WS, DOLLAR_SIGN, UNDERSCORE};

bool get_token(std::string &s)
{
    StdinFilter filter;
    char next_char = filter.get_char();
    int state = 0, next_state;
    std::vector<std::array<int, NUM_COLUMNS>> table = get_FSA_table();

    while (state < 5) // not final state
    {
        state = 5;
    }

    if (std::cin.eof())
    {
        return 0;
    }

    std::string str(1, next_char);

    s = str;

    return 1;
}



// tokenType FADriver() // assume nextChar set, and used as column index
// { 
//     int state, next_state = 0;  // used as row index
//     int next_char;              // used as column index
//     string S = NULL;
    
//     while (state != FINAL)
//     { 
//         next_state = Table[state][nextChar];
        
//         if (next_state == Error)
//         {
//             ERROR(); /* report and exit */
//         }
        
//         if (next_state == FINAL)
//         {
//             if (token(state) == ID) // need reserved keyword lookup
//             {
//                 if (S in Keywords)
//                 {
//                     return (KWtk,S); // or specific keyword
//                 }
//                 else
//                 {
//                     return (IDtk,S);
//                 }
//             }
//             else
//             {
//                 return (Table[state][Token],S);
//             }

//         }
//         else /* not final */
//         {
//             state = next_state;
//             append(S, next_char);
//             next_char = getchar();
//         }
// }