cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_C_FLAGS "-std=c99") 

# adds ./include to compiler include directories 
include_directories(include)

include_directories(tests)

# compiles code files from ./src folder
file(GLOB LIB_SOURCES "src/*.c")

#
# first project (static lib)
# 
project(myuni)

# to build static library target with name libmyuni.a 
add_library(${CMAKE_PROJECT_NAME} STATIC ${LIB_SOURCES})

# to install library headers
install(
    DIRECTORY include/ DESTINATION /usr/local/include 
    FILES_MATCHING PATTERN "*.h"
)

# Set the location for library installation
# Use "sudo make install" in build directory to apply
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/local/lib)


#
# second project(executable)
# 
project(a.out)
# to build executable target with name a.out
add_executable(${CMAKE_PROJECT_NAME} "main.c" "tests/test.c" ${LIB_SOURCES})


# linking libraries

# to link libxml2 XML library
target_link_libraries(${CMAKE_PROJECT_NAME} libxml2.so)

# to link jansson JSON library
target_link_libraries(${CMAKE_PROJECT_NAME} libjansson.so)

# to link progbase library
target_link_libraries(${CMAKE_PROJECT_NAME} check m progbase)
# target_link_libraries(${CMAKE_PROJECT_NAME} libcheck.a)

# uncomment to use libxml2 XML headers
include_directories(/usr/include/libxml2)