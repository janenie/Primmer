#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;
class SmallInt;
class Integral;
class Point
{
public:
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  //prefix
  Point &operator++();
  Point &operator--();
  //postfix, int to identify
  Point operator++(int);
  Point operator--(int);
private:
  int x;
  int y;

  /* data */
};

Point& Point::operator++() {
  x++;
  y++;
  return *this;
}
Point& Point::operator--() {
  x--;
  y--;
  return *this;
}
//postfix add an int as a difference
Point Point::operator++(int a) {
  Point temp(x, y);
  ++x;
  ++y;
  return temp;
  
}

Point Point::operator--(int a) {
  Point temp(x, y);
  --x;
  --y;
  return temp;
  
}
//function object
class Equal {
public:
  Equal(const std::string &a) {
    cmp = a;
  }
  bool operator() (const std::string &s) {
    return s == cmp;
  }  
private:
  std::string cmp;
};
//function call operator
struct  absInt
{
  /* data */
  //function call
  //must be member function and can have many versions
  int operator() (int val) {
    return (val > 0 ? val : -val);
  }
};


//conversion operators
//better to avoid the type conversions with built-in type!
class SmallInt {
public:
  SmallInt(int i = 0): val(i) {
    if (i < 0 || i > 255) {
      throw std::out_of_range("Bad SmallInt initializer");
    }
  }
  //const reference avoid convention ambiguous
  SmallInt(const Integral &a);
  //convert to any type, this is an int type
  operator int() const { return val; }
private:
  std::size_t val;
};

class Integral
{
public:
  Integral(int i = 0): val(i) { }
  operator SmallInt() const {
    if (val < 0 || val > 255) {
      return SmallInt(0);
    }
    return SmallInt(val);
  }
  //the return type must be the const
  //const int();
  //cannot call non-cast funcs and cannot change variables
  //int() const;
  ~Integral(){ }
private:
  int val;
  friend int getVal(const Integral &a);
  /* data */
};

int getVal(const Integral &a) {
  return a.val;
}

SmallInt::SmallInt(const Integral& a) {
  this->val = getVal(a);
  if (this->val < 0 || this->val > 255)
    throw std::out_of_range("Bad initializer");
}


int main() {
  int i = -1;
  absInt absObj;
  std::cout << absObj(i) << std::endl;
  int ival;
  SmallInt si = 3.541;
  ival = static_cast<int>(si) + 3;
  return 0;
}

