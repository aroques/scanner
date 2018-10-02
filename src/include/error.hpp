#ifndef ERROR_HPP
#define ERROR_HPP

const int ERROR = 200;

enum ERROR
{
    START_WITH_UNDERSCORE = ERROR,
    NOT_IN_ALPHABET
};

std::string get_error_reason(int error, char c);

#endif // !ERROR_HPP