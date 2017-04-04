set(PROJECT_TEST_NAME 2_linked_list_test)

file(GLOB SRC_FILES *.cc)

include_directories(${GTEST_INCLUDE_DIRS})
#include_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_TEST_NAME} ${SRC_FILES})
#add_dependencies(${PROJECT_TEST_NAME} googletest)

target_link_libraries(${PROJECT_TEST_NAME}
	linked_list_lib
	${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
)
