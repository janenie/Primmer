#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen {
public:
  typedef std::string::size_type index;
  Screen(std::string c, int& h, int& w) {
    contents = c;
    height = (index)h;
    width = (index)w;
  }
  //overloaded by the CONST Screen object or not
  Screen& display(std::ostream &os) {
    do_display(os); return *this;
  }
  const Screen& display(std::ostream &os) const {
    do_display(os); return *this;
  }
  index get_cursor() const;
private:
  std::string contents;
  index cursor;
  index height, width;  
  void do_display(std::ostream &os) const {
    os << contents;
  }
};

inline Screen::index Screen::get_cursor() const {
  return cursor;
}

//12.18
typedef std::string TYPE;
TYPE initVal();

class Exercise
{
public:
  Exercise() {}
  typedef double TYPE;
  TYPE setVal(TYPE);
  TYPE initVal() {
    return 0.0;
  }
private:
  int val;

  /* data */
};

Exercise::TYPE Exercise::setVal(TYPE parm) {
  val = (int)(parm + initVal());
  return (TYPE)val;
}
int main() {
  
}