#include "rpc/JsonRpcServer.h"

#include <cstddef>
#include <iostream>

#include "rpc/RpcException.h"

namespace lunar
{
namespace rpc
{
    static int WAIT_MSG_TIME = 1000;
    static int PTHREAD_SUCCESS = 0;

    JsonRpcServer::JsonRpcServer( const std::string& address, uint16_t port )
        : TcpServer( address, port )
        , thread( 0 )
        , runing( false )
    {
    }

    JsonRpcServer::JsonRpcServer( uint16_t port )
        : TcpServer( "0.0.0.0", port )
        , thread( 0 )
        , runing( false )
    {
    }

    JsonRpcServer::~JsonRpcServer()
    {
        if( runing )
        {
            Stop();
        }
    }

    void JsonRpcServer::Start()
    {
        if( runing )
        {
            return;
        }

        runing = true;
        try
        {
            if( ! this->Bind() )
            {
                throw RpcException( LUNAR_EXCEPTION_MSG( "Failed at network bind" ) );
            }

            if( ! this->Listen() )
            {
                throw RpcException( LUNAR_EXCEPTION_MSG( "Failed at network listen" ) );
            }

            if( pthread_create( &thread, NULL, JsonRpcServer::Run, this ) != PTHREAD_SUCCESS )
            {
                throw RpcException( LUNAR_EXCEPTION_MSG( "Failed at init thread" ) );
            }
        }
        catch( const std::exception & e )
        {
            runing = false;
            throw e;
        }
    }

    void JsonRpcServer::Stop()
    {
        if( runing )
        {
            runing = false;
            pthread_join( thread, NULL );
            Close();
        }
    }

    void* JsonRpcServer::Run( void *arg )
    {
        JsonRpcServer &server = * ( JsonRpcServer*) arg;
        server.runing = true;

        while( server.runing )
        {
            server.WaitMessage( WAIT_MSG_TIME );
            std::cout << "Listening ..." << std::endl;
        }

        return NULL;
    }
}
}
