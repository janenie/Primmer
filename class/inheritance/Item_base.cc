#include "Item_base.h"

Item_base::Item_base(const Item_base &cop) {
  isbn = cop.isbn;
  price = cop.price;
}

Item_base& Item_base::operator= (const Item_base &cop) {
  this->isbn = cop.isbn;
  price = cop.price;
  return *this;
}
