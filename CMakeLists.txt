project(c)
cmake_minimum_required(VERSION 2.8)

# debug
set(CMAKE_BUILD_TYPE "Debug")

include_directories(/usr/include/c++/7)
include_directories(${PROJECT_SOURCE_DIR}/include)

#add module directory
#add_subdirectory(src)


#include_directories(/usr/include/c++/7)

aux_source_directory(src list)

add_executable(bubble ${list})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
