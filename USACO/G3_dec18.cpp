#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);

	int N, K;
	cin >> N >> K;

	vector<int> A(N + 1), dp(N + 1, 0);
	for (int i=1; i<=N; ++i)
		cin >> A[i];

	for (int i = 1; i <= N; ++i) {
		int mx = 0;
		for (int j = 0; j < K; ++j) {
			if (i-j > 0) {
				mx = max(mx, A[i-j]);
				dp[i] = max(dp[i], dp[i-j-1] + mx*(j+1));
			}
		}
	}
	cout << dp[N] << endl;
	return 0;
}