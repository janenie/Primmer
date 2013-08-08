#include "Bulk_item.h"

//protected and public members allowed to access 
//in derived class
Bulk_item::Bulk_item(const Bulk_item& cop):
              Item_base(cop.getIsbn(), cop.getPrice()) {
  min_qty = cop.min_qty;
  discount = cop.discount;
  limited - cop.limited;
}

Bulk_item& Bulk_item::operator= (const Bulk_item& cop) {
  setIsbn(cop.getIsbn());
  setPrice(cop.getPrice());
  this->min_qty = cop.min_qty;
  this->discount = cop.discount;
  this->limited = cop.limited;
  return *this;
}

double Bulk_item::net_price(std::size_t cnt) const {
  if (cnt >= min_qty) {
    if (cnt <= limited)
      return cnt * (1 - discount) * price;
    else
      return (limited * (1 - discount) + 
              (cnt - limited)) * price;
  }
  else
    return cnt * price;
}
