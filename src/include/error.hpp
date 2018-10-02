#ifndef ERROR_HPP
#define ERROR_HPP

const int ERROR = 200;

enum ERROR
{
    START_WITH_UNDERSCORE = ERROR
};

std::string get_error_reason(int error);

#endif // !ERROR_HPP