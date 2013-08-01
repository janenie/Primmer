#ifndef MESSAGE_H_H
#define MESSAGE_H_H
#include "Folder.h"

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Message {
public:
  Message (const std::string &str = ""): contents(str) {}
  //copy control
  Message (const Message&);
  Message& operator= (const Message&);
  ~Message ();
  
  //add/remove this Message from specified Folder's set of message
  void add (Folder&);
  void remove (Folder&);
private:
  std::string contents;
  std::set<Folder*> folders;
  //utility func used by copy constructors, assignment, and destructors
  void put_Msg_in_Folders(const std::set<Folder*>&);
  void remove_Msg_from_Folders();
};

#endif