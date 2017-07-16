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
             * Start server without block the thread
             *
             * @throws lunar::rpc::RpcException If failed at network bind
             * @throws lunar::rpc::RpcException If failed at network listen
             * @throws lunar::rpc::RpcException If failed at start a new thread
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
