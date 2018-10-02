#include <iostream>

#include "error.hpp"

std::string get_error_reason(int error)
{
    if (error == START_WITH_UNDERSCORE)
    {
        return "no token starts with _";
    }

    return "no error defined for error code " + std::to_string(error);
}