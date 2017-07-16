#include "LunarException.h"
#pragma once

namespace lunar
{
namespace rpc
{
    class RpcException : public lunar::LunarException
    {
        public:
            RpcException( const std::string &what );
            virtual ~RpcException();
    };
}
}
