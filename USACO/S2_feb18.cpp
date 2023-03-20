#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	int N, B; cin >> N >> B;
	vi snow(N);
	vector<ii> boots(B);
	for (int& s : snow) cin >> s;
	for(auto& [s, d] : boots)
		cin >> s >> d;

	vi dp(N, 1e8); dp[0]=0;
	for (int i=0; i<N; ++i) {
		if(dp[i]==1e8) continue;
		for(int j=dp[i]; j<B; ++j) {
			auto [s, d] = boots[j];
			if(s<snow[i]) continue;
			for(int k=i+1; k<=min(N-1, i+d); ++k)
				if(s>=snow[k])
					dp[k] = min(dp[k], j);
		}
	}
	cout << dp[N-1] << endl;
	return 0;
}