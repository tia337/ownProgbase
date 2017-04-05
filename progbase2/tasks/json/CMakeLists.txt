cmake_minimum_required(VERSION 2.8.9)
project (proj)

include_directories(include)
file(GLOB SOURCES "main.c" "src/*.c")


add_executable(proj ${SOURCES})

# adds ./include to compiler include directories

#include_directories(/usr/include/libxml2)

# compiles code files from ./src folder


target_link_libraries(proj libjansson.so)
set(PROJECT_LINK_LIBS libjansson.so)