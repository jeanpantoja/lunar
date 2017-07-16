#pragma once

#include "config/Reader.h"
#include "config/System.h"

namespace lunar
{
namespace core
{
    class Lunar
    {
        public:
            Lunar();
            ~Lunar();
            int Exec( int argc, char **argv );

        private:
            lunar::config::Reader _configReader;
            lunar::config::System _configSystem;
    };
}
}
