#ifndef FOLDER_H_H
#define FOLDER_H_H

#include <iostream>
#include <set>
#include <string>
using namespace std;
//only to declaration this class 
//must use forward declaration
class Message;
class Folder {
public:
  Folder() {}
  Folder(const Folder &);
  Folder& operator= (const Folder &);
  ~Folder();
  //add and remove message from the folder
  void remMsg(Message &);
  void addMsg(Message &);
  
  //get funcs
  // std::set<Message*> getMessages() const;
private:
  std::set<Message*> messages;
};

#endif