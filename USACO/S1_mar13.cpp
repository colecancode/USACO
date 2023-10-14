#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(begin(arr), end(arr));

	vector<pair<int, int>> intervals;
	intervals.emplace_back(0, n-1);
	long long ans = 0;
	int ptr = 0;
	for (int i = 0; ptr < n; ++i) {
		if (i) ans += intervals.size();
		while (ptr < n && arr[ptr].first == i) {
			auto& [val, idx] = arr[ptr++];

			auto it = upper_bound(begin(intervals), end(intervals), make_pair(idx, INT_MAX));
			--it;
			auto& [l, r] = *it;
			if (idx == l || idx == r) {
				if (idx == l && idx == r) intervals.erase(it);
				else if (idx == l) ++l;
				else --r;
			}
			else {
				int tmp = l;
				l = idx + 1;
				intervals.emplace(it, tmp, idx - 1);
			}
		}
	}
	cout << ans;
}