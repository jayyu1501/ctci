cmake_minimum_required(VERSION 2.8)

file(GLOB SRC_FILES *.cc)

add_library(linked_list_lib ${SRC_FILES})
