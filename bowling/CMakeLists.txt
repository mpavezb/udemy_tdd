cmake_minimum_required(VERSION 2.8.11)
project(bowling_game)


# ###########################
# Testing                   #
# ###########################
enable_testing()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(include ${gtest_INCLUDE_DIRS} ${gmock_INCLUDE_DIRS})

# all test/*.cpp files
file(GLOB_RECURSE TEST_SRC_FILES RELATIVE ${PROJECT_SOURCE_DIR} test/*.cpp)

# tests
add_executable(${PROJECT_NAME}_test ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_NAME}_test ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} pthread)
add_test(${PROJECT_NAME}_all_tests ${PROJECT_NAME}_test)

