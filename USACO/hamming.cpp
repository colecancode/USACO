/*
ID: coledou1
TASK: hamming
LANG: C++
*/

// COLE MILLER
// 12 / 20 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>

using namespace std;

int n, b, d;

int hamming(int n, int m) {
	return bitset<8>(n ^ m).count();
}

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	fin >> n >> b >> d;

	vector<int> ans;
	for (int i = 0; i < (1 << b); ++i) {
		bool flag = true;
		for (int n : ans) {
			if (hamming(i, n) < d) {
				flag = false;
				break;
			}
		}

		if (flag) {
			ans.emplace_back(i);
			if (size(ans) == n)
				break;
		}
	}

	for (int i = 0; i < n; ++i) {
		fout << ans[i];
		if ((i + 1) % 10 == 0 || i == n-1)
			fout << endl;
		else
			fout << ' ';
	}

	return 0;
}