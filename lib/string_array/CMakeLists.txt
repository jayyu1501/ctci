cmake_minimum_required(VERSION 2.8)

file(GLOB SRC_FILES *.cc)

add_library(string_array_lib
            ${SRC_FILES})
