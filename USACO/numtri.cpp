/*
ID: coledou1
TASK: numtri
LANG: C++
*/

// COLE MILLER
// 12 / 1 / 22

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int h; fin >> h;

	vector<vector<int>> pyramid;
	for (int i = 0; i < h; ++i) {
		pyramid.push_back(vector<int>(i+1));
		for (int j = 0; j <= i; ++j) fin >> pyramid[i][j];
	}

	for (int i = h - 2; i >= 0; --i)
		for (int j = 0; j <= i; ++j)
			pyramid[i][j] += max(pyramid[i+1][j], pyramid[i+1][j + 1]);

	fout << pyramid[0][0] << endl;

	return 0;
}