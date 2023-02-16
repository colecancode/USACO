#include <iostream>
using namespace std;
#define ll long long

ll solve(ll cur, ll target) {
	ll cnt = 0;

	while (cur > target) {
		if (cur % 2) ++cur;
		else cur /= 2;
		++cnt;
	}
	
	if (cur == target)
		return cnt;
	if (cur + 1 == target)
		return cnt + 1;
	if (target % 2)
		return cnt + solve(cur, target - 1) + 1;
	return min(cnt + target - cur, cnt + solve(cur, target / 2) + 1);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N; cin >> N;
	while (N--) {
		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}

	return 0;
}