#include "Message.h"

Message::Message (const Message& m):
  contents(m.contents), folders(m.folders){
  put_Msg_in_Folders(folders);
}

Message& Message::operator= (const Message& m) {
  if (&m != this){
    this->contents = m.contents;
    this->folders = m.folders;
    put_Msg_in_Folders(folders);
  }
  return *this;
}

void Message::add(Folder& aim) {
  aim.addMsg(*this);
  folders.insert(&aim);
}

void Message::remove(Folder& aim) {
  std::set<Folder*>::iterator it = folders.find(&aim);
  if (it != folders.end()) {
    (*it)->remMsg(*this);
    folders.erase(it);
  }
}

Message::~Message() {
  remove_Msg_from_Folders();
}

void Message::put_Msg_in_Folders (const set<Folder*> &rhs) {
  for (std::set<Folder*>::const_iterator it = rhs.begin();
                                  it != rhs.end(); it++) {
    (*it)->addMsg(*this);
  }
}

void Message::remove_Msg_from_Folders() {
  for (std::set<Folder*>::const_iterator it = folders.begin();
                                  it != folders.end(); it++) {
    (*it)->remMsg(*this);
  }
}

