#include <iostream>
#include <gtest_example/add.h>

int main(int argc, char const *argv[])
{
    std::cout << "Running gtest_example program." << std::endl;
    std::cout << " - (+ 5 2) = " << add(5, 2) << std::endl;
    return 0;
}