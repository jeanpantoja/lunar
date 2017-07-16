#pragma once

#include <json/json.h>
#include "config/System.h"

namespace lunar
{
namespace config
{
    class Reader
    {
        public:
            Reader();
            ~Reader();

            Reader& operator >> ( System & system );

        private:
            const Json::Value& GetSystem();

        private:
            Json::Value _configRoot;
    };
}
}
