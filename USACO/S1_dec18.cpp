#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	int N, M, C;
	cin >> N >> M >> C;

	vector<int> a(N);
	for (int& t : a) cin >> t;
	sort(begin(a), end(a));

	int l = 0, r = a[N - 1];
	for (int i = 0; i < 30; ++i) {
		int mid = (l + r) / 2;

		int ptr = 0;
		for (int m = 0; m < M && ptr < N; ++m)
			ptr = min(
				ptr + C,
				(int)(lower_bound(begin(a), end(a), a[ptr] + mid) - begin(a))
			);
	
		if (ptr == N) r = mid;
		else l = mid;
	}

	cout << r-1 << endl;
	return 0;
}