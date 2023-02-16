/*
ID: coledou1
TASK: barn1
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int boards, stalls, cows;
	fin >> boards >> stalls >> cows;
	
	vi occupied;
	while (cows--) {
		int n; fin >> n;
		occupied.push_back(n);
	}
	sort(occupied.begin(), occupied.end());

	int res = occupied.back() - occupied.front() + 1;
	if (boards == 1) {
		fout << res << endl;
		return 0;
	}

	priority_queue<int, vi, greater<int>> gaps;
	for (int i = 1; i < occupied.size(); ++i) {
		int gap = occupied[i] - occupied[i - 1] - 1;
		if (gaps.size() + 1 == boards && gap > gaps.top()) {
			gaps.pop();
			gaps.push(gap);
		}
		else if (gaps.size() + 1 < boards)
			gaps.push(gap);
	}

	while (!gaps.empty()) {
		res -= gaps.top();
		gaps.pop();
	}

	fout << res << endl;

	return 0;
}