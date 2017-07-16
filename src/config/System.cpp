#include "config/System.h"
#include "config/ConfigurationException.h"

namespace lunar
{
namespace config
{
    const std::string System::ADDRESS_FIELD_NAME( "Address" );
    const std::string System::PORT_FIELD_NAME( "Port" );

    System::System()
        : _address( "0.0.0.0" )
        , _port( 8080 )
    {
    }

    System::~System()
    {
    }

    void System::SetAddress( const std::string &address )
    {
        _address = address;
    }

    void System::SetPort( unsigned int port )
    {
        _port = port;
    }

    const std::string & System::GetAddress() const
    {
        return _address;
    }

    unsigned int System::GetPort() const
    {
        return _port;
    }

    void System::Validate( const Json::Value & system )
    {
        if( ! system.isMember( ADDRESS_FIELD_NAME )
            ||  ! system[ ADDRESS_FIELD_NAME ].isString() )
        {
            throw ConfigurationException(
                    LUNAR_EXCEPTION_MSG( ADDRESS_FIELD_NAME + " is a string required field" ) );
        }

        if( ! system.isMember( PORT_FIELD_NAME )
            ||  ! system[ PORT_FIELD_NAME ].isInt() )
        {
            throw ConfigurationException(
                    LUNAR_EXCEPTION_MSG( PORT_FIELD_NAME + " is a integer required field" ) );
        }
    }

    System& System::operator << ( const Json::Value & system )
    {
        Validate( system );
        SetAddress( system[ ADDRESS_FIELD_NAME ].asString() );
        SetPort( system[ PORT_FIELD_NAME ].asInt() );
        return *this;
    }

    System& System::operator >> ( Json::Value & system )
    {
        system[ ADDRESS_FIELD_NAME ] = GetAddress();
        system[ PORT_FIELD_NAME ] = GetPort();
        return *this;
    }

}
}
