#include <bits/stdc++.h>
using namespace std;

/*
4 
380 166 214 738 
313 658 849 655 
496 719 517 283 
786 61 442 6
*/

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N; cin >> N;
	vector<vector<int>> grid(N, vector<int>(N));
	for(auto& r : grid) for(auto& c : r) cin >> c;

	int h = 0;
	// horizontal
	for (int y = 0; y < N; y++) {
		int sums[2]{ 0, 0 };
		for (int x = 0; x < N; x++)
			sums[x % 2] += grid[y][x];
		h += max(sums[0], sums[1]);
	}

	int v = 0;
	// vertical
	for (int x = 0; x < N; x++) {
		int sums[2]{ 0, 0 };
		for (int y = 0; y < N; y++)
			sums[y % 2] += grid[y][x];

		v += max(sums[0], sums[1]);
	}

	cout << max(h, v) << endl;
	return 0;
}