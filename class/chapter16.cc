#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <set>

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

Item_base::Item_base(const Item_base &cop) {
  isbn = cop.isbn;
  price = cop.price;
}

Item_base& Item_base::operator= (const Item_base &cop) {
  this->isbn = cop.isbn;
  price = cop.price;
  return *this;
}

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

//inherint form item_base
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

//use count handle to replace the reference or pointers
class Sales_item
{
public:
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
            
inline bool compare (const Sales_item& lhs, const Sales_item& rhs)
  { return lhs->book() < rhs->book(); }
//containers and handle classes
class Basket {
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

double Basket::total() const {
  double sum = 0.0;
  for (const_iter iter = items.begin(); iter != items.end();
                                        ++iter) {
    sum += (*iter)->net_price(items.count(*iter));
  }
}
//using the dynamic binding
void print_total(std::ostream &os, 
            const Item_base &item, std::size_t n) {
  os << "ISBN: " << item.book() << "\tnumber sold :"
  << n <<"\ttotal price: " << item.net_price(n) << endl;
}

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
  //ba.add_item(to_add2);
  ba.add_item(to_add3);
  std::cout << ba.total() << std::endl;
  
  return 0;
}
