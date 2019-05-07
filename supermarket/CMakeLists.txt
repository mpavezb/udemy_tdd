cmake_minimum_required(VERSION 2.8.11)
project(Supermarket)

add_compile_options(-std=c++11)

# ###########################
# CODE                      #
# ###########################
include_directories(include)

# checkout library
add_library(${PROJECT_NAME} src/Checkout.cpp)


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
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
add_test(${PROJECT_NAME}_all_tests ${PROJECT_NAME}_test)


