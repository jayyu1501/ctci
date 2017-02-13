cmake_minimum_required(VERSION 2.8)

file(GLOB SRC_FILES
    "*.h"
    "*.cc"
)

add_executable(1_3_is_urify ${SRC_FILES})

