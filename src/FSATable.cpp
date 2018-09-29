#include "FSATable.hpp"

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