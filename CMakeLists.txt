cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME_STR ctci)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated)
endif()

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

#-------------------
# set common include folder for module
#-------------------
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

include_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(lib)
add_subdirectory(test)
