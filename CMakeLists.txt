cmake_minimum_required(VERSION 3.0.0)
project(loco-protocol-c VERSION 0.1.0)

add_subdirectory(test)

add_library(loco-protocol-c SHARED loco-protocol-cxx.h loco-protocol-cxx.c)


include(CTest)
enable_testing()
add_test(packet-test test/protocol-test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
