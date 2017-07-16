#include "core/Lunar.h"

#include <cstdio>
#include "rpc/JsonRpcServer.h"

namespace lunar
{
namespace core
{
    Lunar::Lunar()
    {
    }

    Lunar::~Lunar()
    {
    }

    int Lunar::Exec( int argc, char **argv )
    {
        _configReader >> _configSystem;
        lunar::rpc::JsonRpcServer rpc( _configSystem.GetAddress(), _configSystem.GetPort() );

        rpc.Start();
        getchar();
        rpc.Stop();

        return 0;
    }
}
}
