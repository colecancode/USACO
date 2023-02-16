/*
ID: coledou1
TASK: skidesign
LANG: C++
*/

// COLE MILLER
// 11 / 27 / 22

#include <fstream>
#include <iostream>
#include <map>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	int n; fin >> n;
	map<int, int> hills;
	for (int i = 0; i < n; ++i) {
		int k; fin >> k;
		++hills[k];
	}

	// try all possibilities
	int mn = hills.begin()->first,
		mx = (--hills.end())->first,
		dif = mx - mn - 17;
	
	int res(INT_MAX);
	for (int i = 0; i < dif; ++i) {
		int sum(0);
		for (int j = 0; j < i; ++j)
			sum += pow(i - j, 2) * hills[mn + j];
		for (int j = 0; j < dif - i; ++j)
			sum += pow(dif - i - j, 2) * hills[mx - j];
		res = min(res, sum);
	}

	if (res == INT_MAX) res = 0;

	fout << res << endl;

	return 0;
}