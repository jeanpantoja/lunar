#include "rpc/RpcException.h"

namespace lunar
{
namespace rpc
{
    RpcException::RpcException( const std::string &what )
        : LunarException( what )
    {
    }

    RpcException::~RpcException()
    {
    }
}
}
