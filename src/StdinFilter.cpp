#include <iostream>

#include "StdinFilter.hpp"

static const char COMMENT_CHAR = '$'; // The character that starts and ends comments

/*
    Public
*/

bool StdinFilter::get(char &c)
{
    while (std::cin.get(c))
    {
        if (c == COMMENT_CHAR)
        {
            get_first_char_after_comment(c);
        }

        if (isspace(c))
        {
            if (c == '\n') { this->line_number++; }
            
            continue; // skip whitespace
        }

        break;
    }

    return 1;
}

/*
    Private
*/

void StdinFilter::get_first_char_after_comment(char &c)
{
    while (std::cin.get(c))
    {
        if (c == '\n') { this->line_number++; }

        if (c == COMMENT_CHAR) 
        {
            std::cin.get(c);
            break;
        }
    }
}