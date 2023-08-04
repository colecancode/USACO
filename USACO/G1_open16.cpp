#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll solve(int n, vector<ii>& cows) {
	sort(begin(cows), end(cows), [](ii a, ii b) { return a.first < b.first; });

	vi maxY(n+1), minY(n+1);
	minY[n] = 1e9;
	for (int i = n-1; i >= 0; --i) {
		maxY[i] = max(maxY[i+1], cows[i].second);
		minY[i] = min(minY[i+1], cows[i].second);
	}

	ll area = 1e18;
	int mxY = 0, mnY = 1e9;
	for (int i = 0; i+1 < n; ++i) {
		mxY = max(mxY, cows[i].second);
		mnY = min(mnY, cows[i].second);

		if (i+1 < n && cows[i].first == cows[i+1].first) continue;

		area = min(area, ll(cows[i].first - cows[0].first) * (mxY - mnY) + ll(cows[n-1].first - cows[i+1].first) * (maxY[i+1] - minY[i+1]));
	}
	mxY = max(mxY, cows[n-1].second);
	mnY = min(mnY, cows[n-1].second);
	return ll(cows[n-1].first - cows[0].first) * (mxY - mnY) - area;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

	int n; cin >> n;
	vector<ii> cows(n);
	for (auto& [x, y] : cows)
		cin >> x >> y;

	ll ans = solve(n, cows);
	for (auto& [x, y] : cows) swap(x, y);
	cout << max(ans, solve(n, cows));
}