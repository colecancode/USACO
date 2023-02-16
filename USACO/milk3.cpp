/*
ID: coledou1
TASK: milk3
LANG: C++
*/

// COLE MILLER
// 11 / 27 / 22
// proud of this one

#include <fstream>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

unordered_map<int, unordered_set<int>> mp;
int mxA, mxB, mxC;

int recieve(int b1, int b2, int mx) {
	return min(mx, b1 + b2);
}

int pour(int b1, int b2, int mx) {
	return max(0, b1 - (mx - b2));
}

void dfs(int a, int b, int c) {
	if (mp[a].count(c)) return;
	mp[a].insert(c);
	if (a > 0) {
		if (b < mxB) dfs(pour(a, b, mxB), recieve(a, b, mxB), c);
		if (c < mxC) dfs(pour(a, c, mxC), b, recieve(a, c, mxC));
	}
	if (b > 0) {
		if (a < mxA) dfs(recieve(b, a, mxA), pour(b, a, mxA), c);
		if (c < mxC) dfs(a, pour(b, c, mxC), recieve(b, c, mxC));
	}
	if (c > 0) {
		if (a < mxA) dfs(recieve(c, a, mxA), b, pour(c, a, mxA));
		if (b < mxB) dfs(a, recieve(c, b, mxB), pour(c, b, mxB));
	}
}

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> mxA >> mxB >> mxC;
	dfs(0, 0, mxC);

	vector<int> res;
	for (int n : mp[0]) res.emplace_back(n);
	
	sort(res.begin(), res.end());
	int i;
	for (i = 0; i + 1 < res.size(); ++i)
		fout << res[i] << ' ';
	fout << res[i] << endl;

	return 0;
}