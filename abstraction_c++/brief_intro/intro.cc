#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int prime_table[100001];

void gen_prime() {
  for (int i = 2; i <= 100000; i++) prime_table[i] = 1;
  for (int i = 2; i <= 50000; i++) prime_table[i*2] = 0;
  int p = 2;
  while (p * p <= 100000) {
    p++;
    while (prime_table[p] == 0)
      p++;
    int t = p * p;
    int s = 2 * p;
    while (t <= 100000) {
      prime_table[t] = 0;
      t += s;
    }
  }
}

bool isPerfect(int n) {
  bool flag = false;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (n % i == 0)
      sum += i;
  }
  if (sum == n)
    flag = true;
  return flag;
}

bool isPrime(int i) {
  bool flag = true;
  if (i == 1)
    flag = false;
  for (int j = 2; j <= sqrt(i); j++) {
    if (i % j == 0)
      flag = false;
  }
  return flag;
}

void primeFactor(int n) {
  if (n == 1)
    cout << "no prime factor" << endl;
  int i = 2;
  bool first = true;
  while (n != 1) {
    while (n % i == 0) {
      if (first) {
        cout << i;
        first = false;
      } else {
        cout << "*" << i;
      }
      n = n/i;
    }
    do {
      i++;
    }while(!isPrime(i));
  }
  cout << endl;
}


int main() {
  
  return 0;
}