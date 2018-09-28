#ifndef STDINFILTER_HPP
#define STDINFILTER_HPP

class StdinFilter
{
public:
    int line_number = 1;

    char get_char();
    
private:
    char get_first_char_after_comment();
};

#endif // !STDINFILTER_HPP