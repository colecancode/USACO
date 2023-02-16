#include <iostream>
using namespace std;
#define ll long long

int n;
ll A[7];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	cin >> n;
	ll ans = 0, sum = 0;
	for (ll i = 1; i <= n; ++i) {
		ll m; cin >> m;
		sum = (sum + m) % 7;

		if (!A[sum]) A[sum] = i;
		else         ans = max(ans, i - A[sum]);
	}

	cout << ans << endl;

	return 0;
}