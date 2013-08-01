#include "Folder.h"

Folder::Folder(const Folder &m) {
  for (std::set<Message*>::const_iterator it = 
              (m.messages).begin();it != 
              (m.messages).end(); it++) {
    messages.insert(*it);
  }
}

// std::set<Message*> Folder::getMessages() const{
//   std::set<Message*> aims;
//   for (std::set<Message*>::iterator it = messages.begin(); it !=
//                                           messages.end(); it++)
//     aims.insert(*it);
//   return aims;
// }

Folder& Folder::operator= (const Folder &m) {
  if (&m != this) {
    for (std::set<Message*>::const_iterator it = 
         (m.messages).begin();it != 
         (m.messages).end(); it++) {
     (this-> messages).insert(*it);
    }

  }
  return *this;
}

Folder::~Folder() {
  messages.clear();
}

void Folder::addMsg(Message &m) {
  messages.insert(&m);
}

void Folder::remMsg(Message &m) {
  std::set<Message*>::iterator it = messages.find(&m);
  if (it != messages.end()) {
    messages.erase(it);
  }
}
