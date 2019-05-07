#include <supermarket/Checkout.h>

namespace sm {

Checkout::Checkout() {

}

Checkout::~Checkout() {
  
}

void Checkout::addItem(std::string item) {
  auto it = prices.find(item);
  if (it == prices.end()) {
    throw std::invalid_argument("Invalid item, no price.");
  }
  items[item]++;
}
  
void Checkout::addItemPrice(std::string item, int price) {
  prices[item] = price;
}

int Checkout::calculateTotal() {
  int total = 0;
  for (auto &i_it: items) {
    std::string item = i_it.first;
    int numberOfItems = i_it.second;
    total += calculateItem(item, numberOfItems);
  }
  return total;
}

int Checkout::calculateItem(std::string item, int count) {
  int total = 0;
  auto it = discounts.find(item);
  if (it != discounts.end()) {
    Discount discount = it->second;
    total += calculateDiscount(item, count, discount);
  } else {
    total += count * prices[item];
  }
  return total;
}

int Checkout::calculateDiscount(std::string item, int count, Discount discount) {
  int total = 0;
  if (count >= discount.numberOfItems) {
    int nDiscounts = count / discount.numberOfItems;
    int remainingItems = count % discount.numberOfItems;
    total += nDiscounts * discount.discountPrice;
    total += remainingItems * prices[item];
  } else {
    total += count * prices[item];
  }
  return total;
}

void Checkout::addDiscount(std::string item, int count, int discountPrice) {
  Discount discount;
  discount.numberOfItems = count;
  discount.discountPrice = discountPrice;
  discounts[item] = discount;
}
  
} /* namespace sm */
