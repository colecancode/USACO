/*
ID: coledou1
TASK: friday
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

typedef vector<int> vi;

int isLeapYear(int n) {
	if ((n % 100 && n % 4 == 0) || (1900 + n) % 400 == 0)
			return 1;
	return 0;
}


int days(int m, int y) {
	vi months = {31, 28 + isLeapYear(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return months[m];
}

int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n; fin >> n;

	vi counter(7);
	int weekday = 2;
	for (int y = 0; y < n; ++y) {
		for (int m = 0; m < 12; ++m) {
			++counter[(weekday + 12) % 7];
			weekday = (weekday + days(m, y)) % 7;
		}
	}

	for (int i = 0; i < 6; ++i)
		fout << counter[i] << ' ';
	fout << counter[6] << endl;

	return 0;
}