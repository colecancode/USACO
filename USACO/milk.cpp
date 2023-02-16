/*
ID: coledou1
TASK: milk
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

typedef vector<pair<int, int>> vii;

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m; fin >> n >> m;

	vii vec(m);
	while (m--)
		fin >> vec[m].first >> vec[m].second;

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (auto pair : vec) {
		if (n <= pair.second) {
			ans += pair.first * n;
			fout << ans << endl;
			return 0;
		}
		ans += pair.first * pair.second;
		n -= pair.second;
	}
	fout << 0 << endl;
	return 0;
}