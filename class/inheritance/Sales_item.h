#ifndef SALS_ITEM_H
#define SALS_ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Item_base.h"
//inherint form item_base
//use count handle to replace the reference or pointers
class Sales_item
{
public:
  //copy control
  Sales_item():p(0), use(new std::size_t(1)) { }
  Sales_item(const Item_base&);
  Sales_item(const Sales_item& i):
                      p(i.p), use(i.use) { ++*use; }
  ~Sales_item() { decr_use(); }
  Sales_item& operator= (const Sales_item& );
  //member access members
  const Item_base *operator->() const { if(p) return p;
              else throw std::logic_error("unbounded Sales_item");}
  const Item_base &operator*() const { if (p) return *p;
              else throw std::logic_error("unbounded Sales_item");}
  //compare functions for associative containers

private:
  Item_base *p;
  std::size_t *use;
  void decr_use() {
    if (--*use == 0){
      delete p;
      delete use;
    }
  }
  /* data */
};


#endif