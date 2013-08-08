#ifndef BULK_ITEM_H
#define BULK_ITEM_H
#include <iostream>
#include <string>
#include <vector>

#include "Item_base.h"

using namespace std;
class Bulk_item: public Item_base {
public:
  //copy control
  Bulk_item(std::size_t qty = 0, double disc_rate = 0.0,
            int lim = 1000):
      min_qty(qty), discount(disc_rate), limited(lim) { }
  Bulk_item(const std::string& book, double sale_price,
            std::size_t qty = 0, double disc_rate = 0.0,
            int lim = 1000):
      Item_base(book, sale_price), 
      min_qty(qty), discount(disc_rate), limited(lim) { }
  Bulk_item(const Bulk_item&);
  Bulk_item& operator= (const Bulk_item&);
  //virtual funcs
  double net_price(std::size_t) const;
  Bulk_item* clone() const
          { return new Bulk_item(*this); }
private:
  std::size_t min_qty;
  double discount;
  //exercise 15.7
  int limited; 
};

#endif