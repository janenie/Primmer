#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

using namespace std;

//8.3
istream& readStream(istream& in) {
  string a;
  while (in >> a)
    cout << a;
  in.clear();
  
  return in;
}

ifstream& open_file(ifstream &in, const string &file) {
  in.close();
  in.clear();
  in.open(file.c_str()); //because this argument is C style
  return in;
}

int main() {
  
  //no copy or assign for IO objects
  ofstream print(ofstream);
  //state -- eof badbit failbit good
  //error detect
  int ival;
  while (cin >> ival, !cin.eof()) {
    if (cin.bad())
      throw runtime_error("IO stream corrupted");
    if (cin.fail()) {
      cerr << "bad data, try again";
      cin.clear(istream::failbit);
      continue;
    }
  }
  
  //unitbuf
  cout << unitbuf << "first" << "second" << nounitbuf;
  
  return 0;
}