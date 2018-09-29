#include "FSATable.hpp"
#include <cstring>

std::vector<std::array<int, NUM_COLUMNS>> get_FSA_table()
{
    std::vector<std::array<int, NUM_COLUMNS>> table;
    table.push_back({1, 2, 3, 9, 0, 4, 5});
    table.push_back({6, 6, 6, 6, 6, 6, 6});
    table.push_back({7, 2, 2, 7, 7, 7, 2});
    table.push_back({8, 8, 3, 8, 8, 8, 8});
    table.push_back({4, 4, 4, 9, 4, 0, 4});
    return table;
}

enum Column {OP_DELIM, LETTER, NUMBER, EOF_CHAR, WS, DOLLAR_SIGN, UNDERSCORE};

int col_idx(char c)
{
    std::string op_delim = "=<>:+-*/%%.(),{};[]";
    if (op_delim.find(c)) { return OP_DELIM; }
    
    if (c == '_') { return UNDERSCORE; }

    if (c == '$') { return DOLLAR_SIGN; }

    if (isspace(c)) { return WS; }

    if (isdigit(c)) { return NUMBER; }

    if (isalpha(c)) { return LETTER; }

    if (c == EOF) { return EOF_CHAR; }

    return -1; // character not matched
}