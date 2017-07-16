#include "LunarException.h"

namespace lunar
{
    LunarException::LunarException(const std::string &what )
        : std::exception()
        ,_what( what )
    {
    }

    LunarException::~LunarException()
    {
    }

    char const* LunarException::what() const noexcept
    {
        return _what.c_str();
    }
}
