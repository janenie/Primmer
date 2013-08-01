#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class NoName {
public:
  NoName():pstring(new std::string), i(0), d(0.0){ }
  NoName(const NoName&);
  NoName& operator= (const NoName&);
  NoName(string *p, int i, double d) : pstring(NULL) {
    if (p)
      pstring = new std::string(*p);
    this->i = i;
    this->d = d;
  }
  //this get func must be const
  //or an error for const object will throw discard quantifier
  std::string getPstring() const { return *pstring; }
  int getI() const { return i;}
  double getD() const {return d;}
  
  ~NoName() {
    if (pstring)
      delete(pstring);
    //pstring = NULL;
  }
private:
  std::string *pstring;
  int i;
  double d;
};

NoName::NoName(const NoName& cops) {
  string to_copy = cops.getPstring();
  pstring = new std::string(to_copy);
  //*pstring = cops.getPstring();
  i = cops.getI();
  d = cops.getD();
  //another method
  //(*this) = cops;
}

NoName& NoName::operator= (const NoName& cops) {
  //must check for it
  //if not, shadow parameter throw
  if (&cops != this) {
    std::string to_copy = cops.getPstring();
    this->pstring = new std::string(to_copy);
    this->i = cops.getI();
    this->d = cops.getD();
  }
  return *this;
}

int main() {
  std::string a = "hello world";
  NoName to_copy(&a, 1, 1.2);
  NoName aim(to_copy);
  NoName aim2 = aim;
  NoName aim3;
  aim3 = aim;
  std::cout << "Pstring through copy is " << aim.getPstring() << std::endl;
  std::cout << "Pstring through aim2 is " << aim2.getPstring() << std::endl;
  std::cout << "Pstring through aim3 is " << aim3.getPstring() << std::endl;
  return 0;
}
