
set(GTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/x_googletest/googletest/include")
set(GTEST_LIB gtest_main gtest)
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(1_string_array)
add_subdirectory(2_linked_list)
