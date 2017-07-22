cmake_minimum_required( VERSION 3.1 )

project( lunar )

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/dependencies/jsoncpp/include
    ${CMAKE_SOURCE_DIR}/dependencies/jsonrpc-cpp/include
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/dependencies
)


file(
    GLOB SOURCES
    src/*.cpp
    src/**/*.cpp
)

set( CMAKE_CXX_STANDARD 11 )

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

