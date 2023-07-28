#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);

	int N; cin >> N;
	vector<int> a(N), b(N), dp(N+1);
	for (int& id : a) cin >> id;
	for (int& id : b) cin >> id;

	for (int i = N-1; i >= 0; --i) {
		for (int j = 0; j < N; ++j)
			if (abs(a[i] - b[j]) <= 4)
				dp[j] = max(dp[j], dp[j+1] + 1);

		int mx = 0;
		for (int j = N-1; j >= 0; --j)
			dp[j] = max(dp[j], mx = max(mx, dp[j]));
	}
	cout << dp[0];
}