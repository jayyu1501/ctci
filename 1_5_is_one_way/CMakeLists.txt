cmake_minimum_required(VERSION 2.8)

file(GLOB SRC_FILES
    "*.h"
    "*.cc"
)

add_executable(1_5_is_one_way ${SRC_FILES})

