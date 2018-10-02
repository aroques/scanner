#include <string>

#include "error.hpp"

std::string get_error_reason(int error, char c)
{
    if (error == START_WITH_UNDERSCORE)
    {
        return "no token starts with '_'";
    }

    if (error == NOT_IN_ALPHABET)
    {
        return "'" + std::to_string(c) + "' character not in alphabet";
    }

    return "no error defined for error code " + std::to_string(error);
}