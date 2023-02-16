#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);

	string s; cin >> s;
	int ans, l, r;
	ans = l = r = 0;

	for (char& c : s) {
		(c == ')') ? ++r : ++l;
		if (r > l) {
			++ans; ++l; --r;
			c = '(';
		}
	}
	reverse(begin(s), end(s));
	l = r = 0;
	for (char& c : s) {
		(c == ')') ? ++r : ++l;
		if (l > r) {
			++ans; ++r; --l;
			c = ')';
		}
	}

	cout << ans << endl;
	return 0;
}