#jsoncpp

set( JSONCPP_WITH_TESTS OFF )
set( JSONCPP_WITH_POST_BUILD_UNITTEST OFF )

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/dependencies/jsoncpp
)

#jsonrpc-cpp
add_custom_command(
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp
    OUTPUT ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp/Makefile
    COMMAND ./autogen.sh
    COMMAND ./configure
        --with-jsoncpp-inc-dir=${CMAKE_SOURCE_DIR}/dependencies/jsoncpp/include
        --enable-shared=no
        --enable-examples=no
        --enable-doc=no
)

add_custom_target(
    jsonrpc-cpp_lib_static
    DEPENDS ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp/Makefile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp
    COMMAND make
    COMMENT "Compiling jsonrpc-cpp"
)

#cgicc
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/dependencies/cgicc
)

add_custom_target(
    lunar_dependencies
)

add_dependencies(
    lunar_dependencies
    jsoncpp_lib_static
    jsonrpc-cpp_lib_static
    cgicc
)
