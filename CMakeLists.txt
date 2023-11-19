cmake_minimum_required(VERSION 3.0.0)
project(loco-protocol-c VERSION 0.1.0)

find_package(OpenSSL REQUIRED)
find_library(
    BSON_LIBRARY
    NAMES bson-1.0
)

message(STATUS "finded bson - ${BSON_LIBRARY}")

add_subdirectory(test/protocol-test)
add_subdirectory(test/strgen-test)

add_library(loco-protocol-c SHARED loco-protocol-cxx.c strgen.c loco-packet-generator.c methods/getconf.c)

target_link_libraries(loco-protocol-c OpenSSL::SSL OpenSSL::Crypto ${BSON_LIBRARY})


include(CTest)
enable_testing()
add_test(packet-test test/protocol-test/protocol-test)
add_test(strgen-test test/strgen-test/strgen-test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
