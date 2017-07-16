#pragma once
#include <jsonrpc.h>
#include <pthread.h>

namespace lunar
{
namespace rpc
{
    using Json::Rpc::TcpServer;

    class JsonRpcServer : public TcpServer
    {
        public:
            JsonRpcServer( const std::string& address, uint16_t port );
            JsonRpcServer( uint16_t port );
            ~JsonRpcServer();

            /**
             * */
            void Start();

            /**
             * */
            void Stop();

        private:
            static void* Run( void* arg );

        private:
            pthread_t thread;
            bool runing;
    };
}
}
