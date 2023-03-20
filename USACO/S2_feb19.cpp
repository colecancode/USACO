#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	int N, K; cin >> N >> K;

	vector<vi> grid(1001, vi(1001));
	while (N--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i=y1; i<y2; ++i)
			++grid[i][x1], --grid[i][x2];
	}

	int ans = 0;
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			if (j > 0) grid[i][j] += grid[i][j - 1];

			if (grid[i][j] == K) ++ans;
		}
	}

	cout << ans << endl;
	return 0;
}