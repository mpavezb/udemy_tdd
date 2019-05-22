cmake_minimum_required(VERSION 2.8.11)
project(gtest_example)


# ###########################
# CODE                      #
# ###########################
include_directories(include)

# add library
add_library(${PROJECT_NAME}_library src/add.cpp)
target_include_directories(${PROJECT_NAME}_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# main
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_NAME}_library)


# ###########################
# Testing                   #
# ###########################
enable_testing()
find_package(GTest REQUIRED)
include_directories(${gtest_INCLUDE_DIRS})

# all test/*.cpp files
file(GLOB_RECURSE TEST_SRC_FILES RELATIVE ${PROJECT_SOURCE_DIR} test/*.cpp)

# tests
add_executable(${PROJECT_NAME}_test ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME}_library ${GTEST_BOTH_LIBRARIES} pthread)
add_test(${PROJECT_NAME}_all_tests ${PROJECT_NAME}_test)

