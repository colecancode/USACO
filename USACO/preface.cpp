/*
ID: coledou1
TASK: preface
LANG: C++
*/

// COLE MILLER
// 12 / 21 / 22

#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

string numerals[13]{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int values[13] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

unordered_map<char, int> mp;

void count(int n) {
	for (int i = 0; i < 13; ++i) {
		while (n >= values[i]) {
			n -= values[i];
			for (char c : numerals[i])
				++mp[c];
		}
	}
}

int main() {
	ifstream fin("preface.in");
	ofstream fout("preface.out");

	int n; fin >> n;
	for (int i = 1; i <= n; ++i)
		count(i);
	
	for (char c : "IVXLCDM")
		if (mp[c])
			fout << c << ' ' << mp[c] << endl;

	return 0;
}