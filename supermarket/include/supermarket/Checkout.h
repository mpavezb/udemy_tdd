#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include <map>
#include <string>

namespace sm {

class Checkout {
public:
  Checkout();
  virtual ~Checkout();

  void addItem(std::string item);
  void addItemPrice(std::string item, int price);
  void addDiscount(std::string item, int count, int discount);
  int calculateTotal();

private:
  struct Discount {
    int numberOfItems;
    int discountPrice;
  };
  std::map<std::string, int> items;
  std::map<std::string, int> prices;
  std::map<std::string, Discount> discounts;

  int calculateItem(std::string item, int count);
  int calculateDiscount(std::string item, int count, Discount discount);
};

} /* namespace sm */
#endif /* CHECKOUT_H_ */
