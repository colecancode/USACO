#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> spring;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	int n, p; cin >> n >> p;

	vector<spring> arr(2*p + 2); // springboards (starts and ends)
	vector<int> gap(p+1);
	for (int i = 1; i <= p; ++i) {
		auto& [fromX, fromY, fromI] = arr[2*i];
		auto& [toX, toY, toI] = arr[2*i+1];
		fromI = toI = i;

		cin >> fromX >> fromY >> toX >> toY;
		gap[i] = toX - fromX + toY - fromY;
	}

	sort(begin(arr), end(arr));
	vector<int> ans(p+1, -1);
	map<int, int> skip;
	skip[n] = 0;
	skip[-1] = INT_MAX;
	for (int i = 2*p + 1; i >= 0; --i) {
		auto [x, y, idx] = arr[i];
		auto it = skip.lower_bound(y);
		auto& [Y, _ans] = *it;

		if (ans[idx] == -1) ans[idx] = _ans;
		else ans[idx] = max(_ans, ans[idx] + gap[idx]);

		//cout << endl << endl;
		//for (auto [__y, __ans] : skip) cout << "(" << __y << ' ' << __ans << ") ";
		//cout << endl << x << ' ' << y << ' ' << ans[idx] << endl;

		for (auto _it = next(it, -1); it != begin(skip);) {
			if (_it->second > ans[idx]) break;

			auto nxt = next(_it, -1);
			skip.erase(_it);
			_it = nxt;
		}
		skip[y] = max(skip[y], ans[idx]);

		//for (auto [__y, __ans] : skip) cout << "(" << __y << ' ' << __ans << ") ";
	}
	cout << 2*n - ans[0];
}