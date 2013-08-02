#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
//copying a pointer only copies 
//the address in the pointer
//smart pointer add use count
//for referecing times for a ptr
//when it becomes 0, ptr delete
class U_ptr {
private:
  friend class HasPtr;
  int *ip;
  size_t use;
  U_ptr(int *p): ip(p), use(1) {}
  // U_ptr(const U_ptr&);
  // U_ptr& operator= (const U_ptr&);
  ~U_ptr() { delete ip;}
};

// U_ptr& U_ptr::operator= (const U_ptr& uptr) {
//   if (&uptr != this) {
//     this->ip = uptr.ip;
//     if (this->use != 0)
//       this->use++;
//     else this->use = 1; 
//   }
//   return *this;
// }

// U_ptr::U_ptr (const U_ptr &p) {
//   ip = p.ip;
//   if (use != 0)
//     use++;
//   else use = 1;
// }

class HasPtr {
public:
  HasPtr(int *p, int i): val(i) { ptr = new U_ptr(p); }
  HasPtr(const HasPtr &orig):
    ptr(orig.ptr), val(orig.val) { ++ptr->use;}
  HasPtr& operator= (const HasPtr &);
  //if count goes to zero
  ~HasPtr() { if(--ptr->use == 0) delete ptr;}
  //accessors from U_ptr
  int *get_ptr() const { return ptr->ip; }
  int get_int() const { return val; }
  //change the approporiate data member
  void set_ptr(int *p) { ptr->ip = p;}
  void set_int(int i) { val = i; }
  //get the ptr val
  int get_ptr_val() const { return *ptr->ip; }
  void set_ptr_val(int i) { *ptr->ip = i; }
private:
  U_ptr *ptr;
  int val;
};

HasPtr& HasPtr::operator= (const HasPtr &orig) {
  ++orig.ptr->use;
  bool flag = false;
  U_ptr *temp = ptr;
  if (--ptr->use == 0)
    flag = true;
  ptr = orig.ptr;
  val = orig.val;
  if (flag)
    delete temp;
  return *this;
}

int main() {
  int *p = new int(42);
  int *p1 = new int(50);
 // U_ptr p1(p);
  HasPtr p2(p, 1);
  HasPtr p3(p1, 2);
  p3 = p2;
  std::cout << p3.get_ptr_val() << std::endl;
  return 0;
  
}