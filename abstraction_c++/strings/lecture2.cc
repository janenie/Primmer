#include <iostream>
#include <string>
#include <vector>
#include <cctype>
//#include "strlib.h"

using namespace std;

int judgeRoot(int num) {
  if (num < 10)
    return num;
  else {
    int result = 0;
    while (num != 0) {
      result += num % 10;
      num /= 10;
    }
    return judgeRoot(result);
  }
}

int sumOfDigit(int num) {
  if (num < 10)
    return num;
  else {
    return (num%10) + sumOfDigit(num/10);
  }
}

enum Week {
  Mon,
  Tue,
  Wed,
  Thur,
  Fri,
  Sat,
  Sun
};

Week getDay(Week a, int delta) {
  int aim = (int)a + delta;
  if (aim < 0) aim += 7;
  if (aim > 7) aim %= 7;
  return (Week)(aim);
}

void printHistogram(int arr[], int n) {
  int max = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  while (max > 0) {
    for (int i = 0; i < n; i++) {
      if (arr[i] < max)
        cout << "  ";
      else cout << "* ";
    }
    max--;
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << endl;
}

string reverseString(string aim) {
  //if it is only one, then reverse is done
  if (aim.length() == 1) {
    return aim;
  } else {
    string sub = aim.substr(1);
    return reverseString(sub) + aim[0];
  }
}

bool palindromes(string a) {
  //if it is empty or just one, then true
  if (a.length() <= 1)
    return true;
  else {
    if (a[0] != a[a.length()-1])
      return false;
    else return palindromes(a.substr(1, a.length()-2));
  }
  
}

//better conversion--no need to copy string each time
bool checkPalindromes(string a, int first, int last) {
  if (first >= last)
    return true;
  else 
    return (a[first] == a[last] &&
              checkPalindromes(a, first+1, last-1));
}

int main() {
  //test the printHistogram for right or wrong
  int arr[11] = {0, 0, 0, 0, 1, 1, 0, 2, 5, 2, 1};
  printHistogram(arr, 11);
  
  string aim;
  cout << "Please input a word"<< endl;
  cin >> aim;
  cout << "the reverse is " << reverseString(aim) << endl;
  //test the prime version
  cout << "Please input a sentance" << endl;
  cin >> aim;
  if (palindromes(aim))
    cout << "it is a palindrome" << endl;
  else cout << "it is not a palindrome" << endl;
  //test the better version
  if (checkPalindromes(aim, 0, aim.length()-1))
    cout << "it is a palindrome" << endl;
  else cout << "it is not a palindrome" << endl;
  
  
  return 0;
}