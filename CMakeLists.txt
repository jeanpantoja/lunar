cmake_minimum_required(VERSION 3.8)

project( lunar )

file(
    GLOB SOURCES
    src/*.cpp
    src/**/*.cpp
)

set( CMAKE_CXX_STANDARD 11 )

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/dependencies/jsoncpp/include
    ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp/include
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/dependencies
)

add_executable(
    lunar
    ${SOURCES}
)

add_dependencies(
    lunar
    lunar_dependencies
)

target_link_libraries(
    lunar
    ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp/src/.libs/libjsonrpc-cpp.a
    ${CMAKE_SOURCE_DIR}/build/dependencies/jsoncpp/src/lib_json/libjsoncpp.a
    pthread
)

