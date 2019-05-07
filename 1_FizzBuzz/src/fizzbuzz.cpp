#include <FizzBuzz/fizzbuzz.h>

bool isMultiple(int value, int base) {
  return value % base == 0;
}

std::string fizzBuzz(int value) {
  if (isMultiple(value, 3) && isMultiple(value, 5)) return "FizzBuzz";
  if (isMultiple(value, 3)) return "Fizz";
  if (isMultiple(value, 5)) return "Buzz";
  return std::to_string(value);
}
