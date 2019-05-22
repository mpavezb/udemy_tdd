#include <gtest/gtest.h>
#include <gtest_example/add.h>

TEST (AddTest, TwoAndTwo) {
    ASSERT_EQ (add(2, 2), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
