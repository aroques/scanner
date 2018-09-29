#ifndef FSATABLE_HPP
#define FSATABLE_HPP

#include <vector>
#include <array>

static const int NUM_COLUMNS = 7;

std::vector<std::array<int, NUM_COLUMNS>> get_FSA_table();

#endif // !FSATABLE_HPP