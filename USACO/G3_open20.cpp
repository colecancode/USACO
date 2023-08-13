#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

const int INF = 1e8;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);

	ll N, M;
	cin >> N >> M;

	ll ans = 0;
	vi dp(5e5+1, INF);
	for (ll i = 1; i <= 5e5; ++i) {
		if (i <= N) dp[i] = i;
		else {
			for (ll j = 1; j * j <= i; ++j)
				if (i % j == 0 && dp[j] != INF && dp[i / j] != INF && lcm(j, i / j) == i)
					dp[i] = min(dp[i], dp[j] + dp[i / j]);
		}
		if (dp[i] <= N)
			(ans += i) %= M;
	}
	cout << ans;
	return 0;
}