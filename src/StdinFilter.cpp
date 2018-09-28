#include <iostream>

#include "StdinFilter.hpp"

static const char COMMENT_CHAR = '$'; // The character that starts and ends comments

/*
    Public
*/

char StdinFilter::get_char()
{
    char c;

    while (std::cin.get(c))
    {
        if (c == COMMENT_CHAR) // start of comment
        {
            c = get_first_char_after_comment();
        }

        if (isspace(c))
        {
            if (c == '\n') { this->line_number++; }
            
            continue; // skip whitespace
        }

        break;
    }

    return c;
}

/*
    Private
*/

char StdinFilter::get_first_char_after_comment()
{
    char c;

    while (std::cin.get(c))
    {
        if (c == '\n') { this->line_number++; }

        if (c == COMMENT_CHAR) 
        {
            std::cin.get(c);
            break;
        }
    }

    return c;
}