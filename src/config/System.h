#pragma once

#include <json/json.h>

#include <string>

namespace lunar
{
namespace config
{
    class System
    {
        static const std::string ADDRESS_FIELD_NAME;
        static const std::string PORT_FIELD_NAME;

        static void Validate( const Json::Value & system );

        public:
            System();
            ~System();

            void SetAddress( const std::string &address );
            void SetPort( unsigned int port );

            const std::string & GetAddress() const;
            unsigned int GetPort() const;

            System& operator >> ( Json::Value & system );
            System& operator << ( const Json::Value & system );

        private:
            std::string _address;
            unsigned int _port;
    };
}
}
