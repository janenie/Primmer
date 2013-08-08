#ifndef BASKET_H
#define BASKET_H
#include <set>
#include <iostream>
#include <string>

#include "Sales_item.h"
#include "Item_base.h"

using namespace std;
//compare functions
inline bool compare (const Sales_item& lhs, const Sales_item& rhs)
  { return lhs->book() < rhs->book(); }
//containers and handle classes
class Basket {
  //function pointers for comparing
  typedef bool (*Comp) (const Sales_item&, const Sales_item&);
public:
  typedef std::multiset<Sales_item, Comp> set_type;
  //typedefs
  typedef set_type::size_type size_type;
  typedef set_type::const_iterator const_iter;
  Basket():items(compare) { }
  void add_item(const Sales_item &item)
          { items.insert(item);}
  size_type size(const Sales_item &i) const
          { return items.count(i); }
  double total() const;
private:
  std::multiset<Sales_item, Comp> items;
};

#endif