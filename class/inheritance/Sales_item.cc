#include "Sales_item.h"

Sales_item& 
Sales_item::operator=(const Sales_item &rhs) {
  ++*rhs.use;
  decr_use();
  p = rhs.p;
  use = rhs.use;
  return *this;
}

Sales_item::Sales_item(const Item_base &item):
            p(item.clone()), use(new std::size_t(1)) { }
