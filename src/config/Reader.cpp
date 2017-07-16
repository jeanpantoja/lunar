#include "config/Reader.h"

namespace lunar
{
namespace config
{
    Reader::Reader()
    {
    }

    Reader::~Reader()
    {
    }

    Reader& Reader::operator >> ( System & system )
    {
        system << GetSystem();
        return *this;
    }

    const Json::Value& Reader::GetSystem()
    {
        _configRoot[ "System" ] = Json::Value();
        _configRoot[ "System" ][ "Address" ] = "0.0.0.0";
        _configRoot[ "System" ][ "Port" ] = 8081;
        return _configRoot[ "System" ];
    }
}
}
