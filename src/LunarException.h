#pragma once

#include <stdexcept>
#include <string>

#define LUNAR_EXCEPTION_MSG( MSG ) \
    ( \
      std::string( __PRETTY_FUNCTION__ ) + \
      std::string( ": " ) + \
      MSG \
    )

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
