#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N; cin >> N;

	int minH = 1000;
	vector<int> V(N);
	for (int& h : V) {
		cin >> h;
		minH = min(minH, h);
	}

	int ub = (N % 2 ? minH : 0), ans = 0;
	for (int k = 0; k <= ub; ++k) {
		vector<ll> dp(1005, 1);
		for (int i = N-1; i > 0; --i) {
			vector<ll> cpy = dp;
			ll sum = 0;
			for (int j = 0; j <= V[i - 1] - k; ++j) {
				if (j <= V[i] - k)
					sum = (sum + cpy[j]) % MOD;
				dp[V[i - 1] - j - k] = sum;
			}
		}
		ans = (ans + dp[0]) % MOD;
	}

	cout << ans << endl;
	return 0;
}