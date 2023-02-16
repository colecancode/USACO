/*
ID: coledou1
TASK: castle
LANG: C++
*/

// COLE MILLER
// 12 / 3 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m, // width, height
	k(0); // current component
vector<vector<int>> castle; // matrix
vector<int> sizes(1);

int dfs(int r, int c, int comp) {
	if(castle[r][c] < 0) return 0; // already visited

	int config = castle[r][c];
	castle[r][c] = comp; // component #

	int sz(1);
	// left wall
	if (!(config & 1)) sz += dfs(r, c - 1, comp);
 	// up wall
	if (!(config & 2)) sz += dfs(r - 1, c, comp);
	// right wall
	if (!(config & 4)) sz += dfs(r, c + 1, comp);
	// down wall
	if (!(config & 8)) sz += dfs(r + 1, c, comp);
	
	return sz;
}

int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> n >> m;

	castle = vector<vector<int>>(m, vector<int>(n));

	// read input
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			fin >> castle[i][j];

	// flood fill
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (castle[i][j] >= 0)
				sizes.emplace_back(dfs(i, j, --k));

	int mx(0), x, y;
	char dir;
	for (int j = 0; j < n; ++j) {
		for (int i = m - 1; i >= 0; --i) {
			int comp = castle[i][j]; // component
			// check up
			if (i > 0 && castle[i - 1][j] != comp && sizes[-comp] + sizes[-castle[i - 1][j]] > mx) {
				mx = sizes[-comp] + sizes[-castle[i - 1][j]];
				y = i, x = j;
				dir = 'N';
			}
			// check right
			if (j + 1 < n && castle[i][j+1] != comp && sizes[-comp] + sizes[-castle[i][j + 1]] > mx) {
				mx = sizes[-comp] + sizes[-castle[i][j + 1]];
				y = i, x = j;
				dir = 'E';
			}
		}
	}

	// output:
	// # of rooms
	fout << abs(k) << endl;
	// size of biggest room
	fout << *max_element(sizes.begin(), sizes.end()) << endl;
	// size of biggest room after removing optimal wall
	fout << mx << endl;
	// location of optimal wall
	fout << y+1 << ' ' << x+1 << ' ' << dir << endl;

	return 0;
}