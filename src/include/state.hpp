#ifndef STATE_HPP
#define STATE_HPP

enum State
{
    LEADING_WHITESPACE = 0,
    INSIDE_COMMENT = 4
};

static std::array<int, 2> passive_states = {LEADING_WHITESPACE, INSIDE_COMMENT};

#endif // !STATE_HPP