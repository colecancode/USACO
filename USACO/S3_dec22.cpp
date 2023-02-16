#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ans;
vector<vector<int>> dif;

void dfs(int i) {
	int mx = ans[i - 1] , mn = ans[i - 1];
	for (int j = i-2; j >= 0; --j) {
		mx = max(mx, ans[j]);
		mn = min(mn, ans[j]);
		if (mx - mn != dif[j][i - j - 1])
			return;
	}

	if (i == n) {
		for (int j = 0; j < n; ++j)
			cout << ans[j] << ((j == n - 1) ? '\n' : ' ');
		exit(0);
	}

	ans[i] = ans[i - 1] + dif[i - 1][1];
	dfs(i + 1);
	ans[i] = ans[i - 1] - dif[i - 1][1];
	dfs(i + 1);
}

int main() {
	cin >> n;
	ans.resize(n, 0);
	dif.resize(n);

	for (int i = 0; i < n; ++i) {
		dif[i].resize(n - i);
		for (int j = 0; j < n - i; ++j)
			cin >> dif[i][j];
	}

	dfs(1);

	return 0;
}