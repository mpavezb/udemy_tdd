#include <gtest/gtest.h>
#include <supermarket/Checkout.h>

using namespace sm;

class CheckoutTests: public ::testing::Test {
public:

protected:
  Checkout checkout;
};

TEST_F(CheckoutTests, CanCalculateTotal) {
  checkout.addItemPrice("a", 1);
  checkout.addItem("a");
  int total = checkout.calculateTotal();
  ASSERT_EQ(1, total);
}

TEST_F(CheckoutTests, CanGetTotalForMultipleItems) {
  checkout.addItemPrice("a", 1);
  checkout.addItemPrice("b", 2);
  checkout.addItem("a");
  checkout.addItem("b");
  int total = checkout.calculateTotal();
  ASSERT_EQ(3, total);
}

TEST_F(CheckoutTests, CanAddDiscountRule) {
  checkout.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalculateTotalWithDiscount) {
  checkout.addItemPrice("a", 1);
  checkout.addDiscount("a", 3, 2);
  checkout.addItem("a");
  checkout.addItem("a");
  checkout.addItem("a");
  int total = checkout.calculateTotal();
  ASSERT_EQ(2, total);
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
  ASSERT_THROW(checkout.addItem("a"), std::invalid_argument);
}
