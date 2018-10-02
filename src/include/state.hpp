#ifndef STATE_HPP
#define STATE_HPP

#include <set>

enum State
{
    LEADING_WHITESPACE = 0,
    INSIDE_COMMENT = 4
};

static std::set<int> passive_states = {LEADING_WHITESPACE, INSIDE_COMMENT};



#endif // !STATE_HPP