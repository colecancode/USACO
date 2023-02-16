#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	
	int R, C, K;
	cin >> R >> C >> K;
	vector<vector<int>> dp(R, vector<int>(C)), grid(R, vector<int>(C));
	dp[0][0] = 1;

	for(int i=0; i<R; ++i)
	for(int j=0; j<C; ++j)
		cin >> grid[i][j];

	for(int i=0; i<R; ++i)
	for(int j=0; j<C; ++j)
	for(int k=i+1; k<R; ++k)
	for(int l=j+1; l<C; ++l)
		if (grid[k][l] != grid[i][j]) {
			dp[k][l] += dp[i][j];
			dp[k][l] %= MOD;
		}
	cout << dp[R-1][C-1] << endl;
	return 0;
}