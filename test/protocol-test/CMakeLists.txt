cmake_minimum_required(VERSION 3.0.0)
project(protocol-test)

include_directories(..)
add_executable(protocol-test packet_deandserialize.c)

add_dependencies(protocol-test loco-protocol-c)
target_link_libraries(protocol-test loco-protocol-c)