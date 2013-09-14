#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef pair<string, int> Item;

//10.1
vector<Item> makeIntoPairs(int a[], int a_size, 
  string b[]) {
  vector<Item> aims;
  for (int i = 0; i < a_size; i++) {
    Item it = make_pair(b[i], a[i]);
    aims.push_back(it);
  }
  return aims;
} 

//10.9 -- subscripting
map<string, int> countStringTime(string a[], int ssize) {
  map<string, int> aims;
  for (int i = 0; i < ssize; i++) {
    ++aims[a[i]];
  }
  return aims;
}

//10.12insert count
map<string, int> countStringTimeInsertVer(string a[], int ssize) {
  map<string, int> aims;
  for (int i = 0; i < ssize; i++) {
    pair<map<string, int>::iterator, bool> ret = 
      aims.insert(make_pair(a[i], 1));
    if (!ret.second) {
      ++ret.first->second;
    }
  }
  return aims;
}

int main() {
  //make pair
  pair<string, string> item;
  string first, last;
  cin >> first >> last;
  item = make_pair(first, last);
  string a[6] = {"You", " are", "are", "such", "a", "a"};
  map<string, int> res = countStringTimeInsertVer(a, 6);
  for (map<string, int>::const_iterator it = res.begin();
    it != res.end(); it++) {
    cout << it->first <<" " << it->second << endl;
  }
  //add map find function usage
  map<char, int> mymap;
  mymap['a'] = 50;
  mymap['b'] = 100;
  mymap['c'] = 150;
  mymap['d'] = 200;
  
  map<char, int>::iterator it;
  it = mymap.find('b');
  mymap.erase(it);
  
  cout << "a=>" << mymap.find('a')->second << endl;
  
  return 0;
}