#ifndef STDINFILTER_HPP
#define STDINFILTER_HPP

class StdinFilter
{
public:
    int line_number = 1;

    char get_char();
    
private:
    char get_first_char_after_comment();
    char get_last_whitespace_char(char c);
};

#endif // !STDINFILTER_HPP