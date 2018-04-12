cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME_STR ctci)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated)
endif()

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -O0")
set (CMAKE_CXX_STANDARD 11)

#-------------------
# set common include folder for module
#-------------------
#set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
#add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#google test and google mock
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(x_googletest)

include_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(lib)
add_subdirectory(test)
