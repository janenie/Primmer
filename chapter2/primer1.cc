//this is chapter 2
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cctype>
using namespace std;

int main() {
	string a = "hello!";
	string::size_type punct = 0;

	for (string::size_type index = 0; index < a.size(); ++index) {
		if (ispunct(a[index])) {
			punct++;
		}
	}
	cout << punct << endl;
	string num = "0.6";
	double temp = atof(num.c_str());
	cout << temp << endl;
	
	string strval("1100");
	bitset<32> bitvec(strval); //32 bits zero
	
	string str("11111110000011001101");
	bitset<32> bitvec2(str, 5, 4);
	size_t sz = bitvec2.count(); // num of bits on
	for (int index = 0; index != 32; index++) {
		bitvec2[index] = 1;
	}
	
	bitset<32> bv(1010101);
	for (int i = 0; i < 32; i++) {
		cout << bv[i];
	}
	cout << endl;
	return 0;
}