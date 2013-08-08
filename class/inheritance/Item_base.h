#ifndef ITEM_BASE_H
#define ITEM_BASE_H
#include <iostream>
#include <string>

using namespace std;
class Item_base {
public:
  //constructor shall not be virtual
  //for the dynamic type not completed 
  Item_base(const std::string &book = "",
    double sale_price = 0.0):isbn(book), 
            price(sale_price) { }
  Item_base(const Item_base&);
  Item_base& operator= (const Item_base&);
  std::string book() const { return isbn; }
  //delete the item through pointer 
  //will help
  virtual ~Item_base() { }
  //member functions
  virtual Item_base* clone() const 
            { return new Item_base(*this); }
  //get functions
  std::string getIsbn() const { return isbn; }
  double getPrice() const { return price; }
  //set functions
  void setIsbn(std::string a) { isbn = a; }
  void setPrice(double a) { price = a; }
  //return total sales price for a specific book kind
  //virtual function must pass the same parameter
  virtual double net_price (std::size_t n) const
    { return n * price; }
private:
  std::string isbn;
protected:
  double price;
};

#endif