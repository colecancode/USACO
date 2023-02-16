/*
ID: coledou1
TASK: palsquare
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

char toChar(int n) {
	if (n < 10)
		return n + '0';
	return (n - 10) + 'A';
}

string toBase(int n, int base, string s="") {
	if (n < base) {
		s.insert(s.begin(), toChar(n));
		return s;
	}
	int rem = n % base;
	return toBase(n / base, base, s) + toChar(rem);
}

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int base; fin >> base;
	for (int i = 1; i <= 300; ++i) {
		string sqr = toBase(pow(i, 2), base);
		int n = size(sqr),
			j = 0;
		for (; j < n / 2; ++j) {
			if (sqr[j] != sqr[n - j - 1]) {
				j = -1;
				break;
			}
		}
		if (j >= 0)
			fout << toBase(i, base) << ' ' << sqr << endl;
	}

	return 0;
}