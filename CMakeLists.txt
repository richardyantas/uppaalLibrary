cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 17) # problems with filesystem -> experimental/filesystem
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-g -fno-omit-frame-pointer -Wall")

project (jsonreader)
#include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(lib/jsoncpp/)
add_subdirectory(config/)
add_subdirectory(test/)