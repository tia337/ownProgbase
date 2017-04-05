cmake_minimum_required(VERSION 2.8.9)
project (proj)

include_directories(include )
include_directories(/usr/include/libxml2)
file(GLOB SOURCES "main.c" "src/*.c" "tests/*.c" )
install(
    DIRECTORY include/ DESTINATION /usr/local/include
    FILES_MATCHING PATTERN "*.h"
)


add_executable(proj ${SOURCES})

# adds ./include to compiler include directories

#include_directories(/usr/include/libxml2)

# compiles code files from ./src folder


target_link_libraries(proj libxml2.so)
target_link_libraries(proj progbase.a)
target_link_libraries(proj libcheck.so)
