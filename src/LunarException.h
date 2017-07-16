#pragma once

#include <stdexcept>
#include <string>

namespace lunar
{
    class LunarException : public std::exception
    {
        public:
            LunarException( const std::string &what );
            virtual ~LunarException();

            char const* what() const noexcept;

        private:
            std::string _what;
    };
}
