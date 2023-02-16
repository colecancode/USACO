/*
ID: coledou1
TASK: ariprog
LANG: C++
*/

// COLE MILLER
// 11 / 27 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m;
bitset<125001> bs;
set<int> mySet;

bool check(int s, int d) {
	for (int i = 0; i < n; ++i)
		if (!bs[s + i * d]) return false;

	return true;
}

int main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	fin >> n >> m;

	// bisquares
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= m; ++j) {
			bs[i * i + j * j] = 1;
			mySet.insert(i * i + j * j);
		}

	map<int, vector<int>> res;

	int k = m * m * 2;
	for (int s : mySet)
		for (int d = 1; d <= (k - s) / (n - 1); ++d)
			if (check(s, d))
				res[d].push_back(s);

	// write output
	for (auto it : res)
		for (int x : it.second)
			fout << x << ' ' << it.first << endl;

	if (res.empty()) fout << "NONE" << endl;

	return 0;
}