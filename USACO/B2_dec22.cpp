#include <iostream>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	string s, ans(n, '.'); cin >> s;

	if (k == 0) {
		cout << n << endl << s << endl;
		return;
	}

	int patches = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'G') {
			++patches;
			ans[min(n - 1, i + k)] = 'G';
			i = i + k + k;
		}
	}
	for (int i = 0; i < n; ++i)
		if (s[i] == 'H')
			for (int j = min(n - 1, i + k); j >= 0; --j)
				if (ans[j] == '.') {
					++patches;
					ans[j] = 'H';
					i = j + k;
					break;
				}

	cout << patches << endl
		 << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}