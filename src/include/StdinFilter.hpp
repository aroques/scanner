#ifndef STDINFILTER_HPP
#define STDINFILTER_HPP

class StdinFilter
{
public:
    int line_number = 1;

    bool get(char &c);
    
private:
    void get_first_char_after_comment(char &c);
};

#endif // !STDINFILTER_HPP