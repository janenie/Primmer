#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

//exercise 9.12
bool findValue(int value, vector<int> a) {
  std::vector<int>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    if (*it == value)
      return true;
  }
  return false;
}

//exercise 9.13
vector<int>::iterator findValueReturn(int value, vector<int> a) {
  std::vector<int>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    if (*it == value)
      return it;
  }
  return a.end();
}

void moveListToDeques(const list<int> a, deque<int> &e, deque<int> &o) {
  e.clear();
  o.clear();
  int count = 0;
  for (list<int>::const_iterator it = a.begin(); it != a.end(); it++) {
    if (count % 2 == 0) 
      e.push_back(*it);
    else
      o.push_back(*it);
  }
}

void printList(string a[], int size) {
  list<string> slist;
  for (int i = 0; i < size; i++) {
    slist.push_back(a[i]);
  }
  
  for (list<string>::iterator it = slist.begin(); 
    it != slist.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
	char *words[] = {"stately", "plump", "buck"};
	size_t word_size = sizeof(words) / sizeof(char*);
	list<string> words2(words, words + word_size);
	//for sequential contianer only
	list<string> slist(64, "eh");
	list<int> ilist(64);
  
  string ss[5] = {"i ", "want ", "barbie ", "x8253", " !!!"};
  printList(ss, 5);
  
  deque<int> e;
  deque<int> o;
  moveListToDeques(ilist, e, o);
  
  return 0;
}