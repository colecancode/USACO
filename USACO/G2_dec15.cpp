#include <iostream>
using namespace std;

int T, A, B;
int ans = 0;
bool seen[5000005];

void solve(int amt, bool used) {
	if (seen[amt]) return;

	seen[amt] = 1;
	ans = max(ans, amt);
	if (amt + A <= T) solve(amt + A, used);
	if (amt + B <= T) solve(amt + B, used);
	if (!used) solve(amt / 2, 1);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

	cin >> T >> A >> B;
	solve(0, 0);
	cout << ans << endl;

	return 0;
}