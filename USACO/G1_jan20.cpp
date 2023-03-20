#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1005;
const int MAXT = 1005;

ll n, m, c;
ll value[MAXN];
ll dp[2][MAXN];

vector<pair<int, int>> edges;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges.emplace_back(a, b);
	}
	ll max_profit = 0;
	memset(dp, -1, sizeof dp);
	dp[0][1] = 0;
	for (int t = 1; t < MAXT; t++) {
		int p = t % 2;
		memset(dp[p], -1, sizeof dp[p]);
		for (auto [a, b] : edges)
			if (dp[1 - p][a] >= 0)
				dp[p][b] = max(dp[p][b], dp[1 - p][a] + value[b]);

		max_profit = max(max_profit, dp[p][1] - c * t * t);
	}
	cout << max_profit << endl;
}