cmake_minimum_required(VERSION 3.0.0)
project(strgen-test)

include_directories(..)
add_executable(strgen-test strgen_test.c)

add_dependencies(strgen-test loco-protocol-c)
target_link_libraries(strgen-test loco-protocol-c)