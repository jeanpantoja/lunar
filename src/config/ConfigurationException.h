#pragma once

#include "LunarException.h"

namespace lunar
{
namespace config
{
    class ConfigurationException : public LunarException
    {
        public:
            ConfigurationException( const std::string &what );
            ~ConfigurationException();
    };
}
}
