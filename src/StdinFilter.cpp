#include <iostream>

#include "StdinFilter.hpp"

static const char COMMENT_CHAR = '$'; // The character that starts and ends comments

/*
    Public
*/

char StdinFilter::get_char()
{
    char c = EOF;

    while (std::cin.get(c))
    {
        if (c == COMMENT_CHAR) // start of comment
        {
            c = get_first_char_after_comment();
        }

        if (isspace(c))
        {
            c = get_last_whitespace_char(c);
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


char StdinFilter::get_last_whitespace_char(char c)
{
    char next_char;

    while (std::cin.get(next_char))
    {
        if (next_char == '\n') { this->line_number++; }

        if (!isspace(next_char)) 
        {
            std::cin.unget();
            break;
        }
        
        c = next_char;
    }

    return c;
}