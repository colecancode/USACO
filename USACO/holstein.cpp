/*
ID: coledou1
TASK: holstein
LANG: C++
*/

// COLE MILLER
// 12 / 7 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX_G = 1000;
const int MAX_V = 15;

int V, G,
	r[MAX_G],
	s[MAX_G+10][MAX_V+10];

vector<int> used, ansVec;
int ans = MAX_V + 1;

void dfs(int i) {
	if (i == G) {
		for (int j = 0; j < V; ++j) {
			int sum = 0;
			for (int k : used)
				sum += s[k][j];

			if (sum < r[j])
				return;
		}

		if (size(used) < ans) {
			ans = size(used);
			ansVec = used;
		}
		return;
	}
	used.emplace_back(i);
	dfs(i + 1);
	used.pop_back();
	dfs(i + 1);
}

int main() {
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");

	fin >> V;
	for (int i = 0; i < V; ++i)
		fin >> r[i];

	fin >> G;
	for (int i = 0; i < G; ++i)
		for (int j = 0; j < V; ++j)
			fin >> s[i][j];

	dfs(0);

	fout << ans;
	for (int n : ansVec) fout << ' ' << n + 1;
	fout << endl;

	return 0;
}