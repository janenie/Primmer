#include "Message.h"
#include "Folder.h"

int main() {
  const string a = "this is the folder";
  Message m("Check it out");
  Message m1(a);
  Message m2(m1);
  Folder f1;
  m1.add(f1);
  m.add(f1);
  Folder f2 = f1;
  
  return 0;
}