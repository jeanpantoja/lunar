#pragma once

#include "LunarException.h"

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
