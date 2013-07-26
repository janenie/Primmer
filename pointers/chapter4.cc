#include <iostream>
#include <string>
#include <vector>

using namespace std;
//pointer to functions
//function type is determined by the arguments' type
//return type, the function name is not!!!
bool lengthCompare (const string &a, const string &b) {
  return a.size() == b.size();
}

bool AscendingCompare(const int &a, const int &b) {
  return a > b;
}

bool DescendingCompare(const int &a, const int &b) {
  return a < b;
}

vector<int> sorting(int a[], int size, bool (*cmp)(const int&, const int&)) {
  int k = 0;
  for(int i = 0; i < size; i++) {
    k = i;
    for (int j = i+1; j < size; j++) {
      if (cmp(a[j], a[k])) //compare rules through the pointer
        k = j;
    }
    if (k != i) {
      int temp = a[i];
      a[i] = a[k];
      a[k] = temp;
    }
  }
  vector<int> aim;
  for (int i = 0; i < size; i++) {
    aim.push_back(a[i]);
  }
  return aim;
}

void tranverse(vector<int> res1) {
  for (vector<int>::const_iterator it = res1.begin(); it != 
      res1.end(); it++)
    cout << *it << " ";
  cout << endl;
}

//returning a pointer to function
typedef int (*PF) (int*, int);
PF ff(int); //ff(int) return the pointer

int main() {
  int *pi = 0; //initialized to address no object
  int ia[] = {1, 2, 3, 4};
  int *p1 = ia;
  int *p2 = p1 + 4;
  //ptrdiff n = p2 - p1;
  //definition of the function pointer
  typedef bool (*cmpFcn)(const string &, const string &);
  cmpFcn ptr1 = lengthCompare; //make a function pointer
  
  //it's most common use is to pass as the argument in a function
  int a[10] = {6, 55, 33, 222, 77, 11, 990, 11, 666, 1};
  bool (*cmp) (const int&, const int&) = AscendingCompare;
  vector<int> res1 = sorting(a, 10, cmp);
  tranverse(res1);
  
  cmp = DescendingCompare;
  res1 = sorting(a, 10, cmp);
  tranverse(res1);
  
  //call the function lengthCompare through ptr1
  ptr1("hi", "hello"); //implicit
  (*ptr1)("hi", "hello");  //explicit
  
  return 0;
  
}