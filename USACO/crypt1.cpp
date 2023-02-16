/*
ID: coledou1
TASK: crypt1
LANG: C++
*/

// NOT MY CODE
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool num[10];
int N;

bool check(int n) {
	while (n > 0) {
		if (!num[n % 10]) return false;
		n /= 10;
	}
	return true;
}

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int a, b, c, tmp, ans(0);
	fin >> N;

	for (int i = 0; i < N; ++i) {
		fin >> tmp;
		num[tmp] = true;
	}

	for (int i = 111; i < 999; ++i) {
		if (!check(i)) continue;

		for (int j = 11; j < 99; ++j) {
			if (!check(j)) continue;

			a = i * (j % 10);
			b = i * (j - j % 10) / 10;
			c = i * j;

			if (a > 999 || b > 999 || c > 9999) continue;

			if (check(a) && check(b) && check(c)) ++ans;
		}
	}
	fout << ans << endl;
}