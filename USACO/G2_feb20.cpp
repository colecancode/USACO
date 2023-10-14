#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int suf[200005], pre[200005], pow2[100005];
pair<int, int> segments[100005];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	int n; cin >> n;

	for (int i = 1; i <= n; ++i) {
		auto& [l, r] = segments[i];
		cin >> l >> r;
		++suf[l];
		++pre[r];
	}
	for (int i = 1; i <= 2*n; ++i)
		pre[i] += pre[i-1];
	for (int i = 2*n; i >= 1; --i)
		suf[i] += suf[i+1];

	pow2[0] = 1;
	for (int i = 1; i <= n; ++i)
		pow2[i] = pow2[i-1] * 2 % MOD;

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		auto& [l, r] = segments[i];
		ans = (ans + (long long)pow2[pre[l - 1]] * pow2[suf[l + 1]]) % MOD;
	}
	cout << ans;
}