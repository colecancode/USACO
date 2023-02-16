/*
ID: coledou1
TASK: dualpal
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

string toBase(int n, int base, string s = "") {
	if (n < base) {
		s.insert(s.begin(), toChar(n));
		return s;
	}
	int rem = n % base;
	return toBase(n / base, base, s) + toChar(rem);
}

int isPalindrome(int n, int base) {
	string s = toBase(n, base);
	int m = size(s);
	for (int i = 0; i < m / 2; ++i)
		if (s[i] != s[m - i - 1])
			return 0;
	return 1;
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s; fin >> n >> s;
	int cnt = 0;

	while (++s) {
		int m = 0;
		for (int i = 2; i <= 10; ++i) {
			m += isPalindrome(s, i);
			if (m >= 2) {
				fout << s << endl;
				++cnt;
				break;
			}
		}
		if (cnt >= n)
			break;
	}

	return 0;
}