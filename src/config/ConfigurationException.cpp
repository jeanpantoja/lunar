#include "config/ConfigurationException.h"

namespace lunar
{
namespace config
{
    ConfigurationException::ConfigurationException( const std::string &what )
        : LunarException( what )
    {
    }

    ConfigurationException::~ConfigurationException()
    {
    }
}
}

