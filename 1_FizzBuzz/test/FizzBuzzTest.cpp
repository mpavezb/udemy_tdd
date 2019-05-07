#include <gtest/gtest.h>
#include <FizzBuzz/fizzbuzz.h>

void checkFizzBuzz(int value, std::string expectedResult) {
  std::string result = fizzBuzz(value);
  ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTest, returns1With1PassedIn) {
  checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTest, returns2With2PassedIn) {
  checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTest, returnsFizzWith3PassedIn) {
  checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith5PassedIn) {
  checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzWith6PassedIn) {
  checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith10PassedIn) {
  checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzBuzzWith15PassedIn) {
  checkFizzBuzz(15, "FizzBuzz");
}
