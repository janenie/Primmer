#include "Basket.h"

double Basket::total() const {
  double sum = 0.0;
  for (const_iter iter = items.begin(); iter != items.end();
                                        ++iter) {
    sum += (*iter)->net_price(items.count(*iter));
  }
  return sum;
}
//using the dynamic binding
void print_total(std::ostream &os, 
            const Item_base &item, std::size_t n) {
  os << "ISBN: " << item.book() << "\tnumber sold :"
  << n <<"\ttotal price: " << item.net_price(n) << endl;
}
