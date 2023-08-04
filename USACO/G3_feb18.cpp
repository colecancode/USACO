#include <bits/stdc++.h>
using namespace std;
#define FOR(s, e, i) for(int i=s; i<e; ++i)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int N;
int arr[105], lst[105], dp[105][105];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i)
		if (i - arr[i] >= 0)
			lst[i] = ++dp[1][i - arr[i]];

	for (int i = 1; i <= N; ++i) {
		cout << N - max(dp[i][0], dp[i-1][1]) << endl;

		for (int j = 0; j < i; ++j)
			dp[i][N-j] = -1e6;

		for (int j = N - i; j >= 0; --j) {
			dp[i][j] = max(dp[i][j], max(dp[i][j+1], dp[i-1][j+1]));

			if (j - arr[j] >= 0)
				dp[i+1][j-arr[j]] = max(dp[i+1][j-arr[j]], lst[j] + dp[i][j+1]);
		}
	}
}