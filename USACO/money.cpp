/*
ID: coledou1
TASK: money
LANG: C++
*/

// COLE MILLER
// 2 / 3 / 23

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int V, N;
	cin >> V >> N;

	vector<int> coins(V);
	vector<vector<ll>> dp(N + 1, vector<ll>(V));
	for (ll& e : dp[0]) e = 1;
	for (int& e : coins) cin >> e;

	for (int i = 1; i <= N; ++i)
	for (int j = 0; j < V; ++j) {
		if(i-coins[j]>=0) dp[i][j] += dp[i-coins[j]][j];
		if(j>0) dp[i][j] += dp[i][j-1];
		}

	cout << dp[N][V - 1] << endl;
	return 0;
}