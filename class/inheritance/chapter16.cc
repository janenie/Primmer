
#include "Item_base.h"
#include "Bulk_item.h"
#include "Sales_item.h"
#include "Basket.h"

using namespace std;


//abstract class
//exercise 15.26
class Disc_item : public Item_base {
public:
  Disc_item(const std::string &book = "", 
            double sale_price = 0.0,
            std::size_t qty = 0, double disc_rate = 0.0):
              Item_base(book, sale_price), 
              quantity(qty), discount(disc_rate) { }
  //pure virtual function ,this object can't be created
  //it's because it needn't the net price at all
  double net_price(std::size_t) const = 0;
  Disc_item* clone() const;
protected:
  std::size_t quantity;
  double discount;
};

int main() {
  Item_base base("abs11111", 35.5);
  Bulk_item derived("ass222", 35.5, 10, 0.9, 100);
  Item_base *baseP = &derived;
  //overriding the virual mechainsm
  double d = baseP->Item_base::net_price(42);
  //virtual destructor
  Item_base *baseP2 = new Item_base;
  delete baseP2;
  baseP2 = new Bulk_item;
  delete baseP2;
  //use Sales_item
  Sales_item to_add(base);
  Sales_item to_add2(derived);
  Sales_item to_add3(to_add);
  //use Basket
  Basket ba;
  ba.add_item(to_add);
  ba.add_item(to_add2);
  ba.add_item(to_add3);
  std::cout << ba.total() << std::endl;
  
  return 0;
}
