cmake_minimum_required(VERSION 2.8.9)

#
# Common settings
#

# adds ./include to compiler include directories
include_directories(include usr/local/include /usr/include/libxml2)
# compiles code files from ./src folder
file(GLOB LIB_SOURCES "src/*.c")
set(PROJECT_LINK_LIBS univers progbase xml2 jansson check)
#
#first project (mylib)
#
project (univers)
# to build static library target with name libmtmodule.a
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
# Second project (executable)
#
project(lab5)
# to build executable target with name a.out
add_executable(${CMAKE_PROJECT_NAME} "main.c")
target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_LINK_LIBS})


#
# Second project (test executable)
#

# Extra



SET(CMAKE_C_FLAGS "-std=c99")